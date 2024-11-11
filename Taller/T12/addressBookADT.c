//
// Created by Catalina Vivern on 01/11/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "addressBookADT.h"

#include <strings.h>

//RTA DE LA CATEDRA

typedef struct nodoP {
    tContact person;
    struct nodoP *tail;
}tNodoP;

typedef struct nodoG {
    char * groupName;
    tNodoP *firstPerson;
    size_t groupDim; //cantidad de contactos del grupo
    struct nodoG *tail;
} tNodoG;

typedef struct addressBookCDT {
    tNodoG * firstGroup;
    tNodoG * currentGroup;
    tNodoP * currentPerson;
    size_t groupCount; //cantidad de grupos //DUDA: Es mejor ponerlo o no ponerlo?
}addressBookCDT;

/* Crea un nuevo TAD vacío */
addressBookADT newAddressBook() {
     //addressBookADT aux = calloc(1, sizeof(addressBookCDT));
    //return aux;
    return calloc(1, sizeof(addressBookCDT));
}


// Almacena un nuevo grupo de contactos. Si el grupo existe, no hace nada.
// No diferencia entre minúsculas y mayúsculas, el grupo "abc" es el mismo que "ABC",
// "Abc", etc. pero distinto que " abc" o "abc "
// Almacena una copia del nombre, que no tiene un límite para su longitud
//
tNodoG * addGroupRec( tNodoG * first, const char * groupNameA, int * ok ) {
    int c;
    if ( first==NULL || (c=strcasecmp(first->groupName, groupNameA))>0 ) {//Si no hay espacio o se puede agregar, q se cree el espacio para el nuevo grupo
        tNodoG * new = malloc(sizeof(tNodoG));
        new->groupName = malloc(sizeof(char)*(strlen(groupNameA)+1)); //NOTA: Esto es un malloc
        strcpy(new->groupName, groupNameA);
        new->groupDim = 0;
        new->firstPerson=NULL;
        new->tail=first; //NOTA:Se agrega al principio de la lista
        *ok=1;
        return new;
    }
    if (c!=0) {
        first->tail = addGroupRec( first->tail, groupNameA, ok );
    }
    return first;
}

int addGroup(addressBookADT ab, const char * groupNameA) {
    if (groupNameA==NULL) {
        return 0;
    }
    int ok=0;
    ab->firstGroup=addGroupRec(ab->firstGroup, groupNameA, &ok); //NOTA: es int ok; &ok
    ab->groupCount+=ok;
    return ok;
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

// Si existe un grupo de nombre groupName, agrega el contacto contact a la agenda
// Si el grupo no existe, no hace nada
// Si el contact ya estaba relacionado al grupo (había uno con el mismo nombre),
// no lo agrega
//
static tNodoG * findGroup( tNodoG * first, const char * groupNameA) { //Estan ordenados alfabeticamente
    int c;
    // int c=strcasecmp(first->groupName,groupNameA); // NO SE PONE ACA PQ SI FIRST FUESE NULL FALLA
    if (first==NULL || (c=strcasecmp(first->groupName,groupNameA))>0) { //Si paso por todos y no lo habia encontrado o si ya no hay chance de q este x el orden
        return NULL;
    }
    if (c==0) { //Si los nombres son iguales q se devuelva el nodo del grupo. NO COMO COPIA
        return first;
    }
    //tiene q seguir el caso rec
    // first->tail=findGroup(first->tail, groupNameA); // COMO NO SE CAMBIA LA LISTA DE FIRST, NO HAY QUE PONER FIRST-> TAIL
    return findGroup(first->tail, groupNameA);
}

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------


static tNodoP * addContactRec( tNodoP *first, tContact contact, size_t * groupDim, int * ok) { //Estan ordenados alfabeticamente
    int c;
    if ( first==NULL || (c=strcasecmp(first->person.name, contact.name))>0) {//CB: q sea NULL// significa q no lo encontro o ya se paso del lugar en dnd tenia q estar
        tNodoP * new = malloc(sizeof(tNodoP)); //NO HACE FALTA HACER CALLOC pq se conectan los punteros, no se agregan cosas
        new->person.name = malloc(strlen(contact.name)+1);
        strcpy(new->person.name, contact.name);
        new->person.phoneNumber = contact.phoneNumber;
        //NO ES ASI new->person=contact;//NO HACE FALTA HACER: new->person.name= contact.name;
        new->tail=first; //Para q new quede antes q el sgte(q es mayor alfabeticamente)
        (*groupDim)++;

        *ok =1;
        return new;
    }
    if (c==0) { //Si son iguales no lo agrega
        // *ok = 0;
        return first; //Para q salga de la ida y termine la vuelta
    }
    first->tail = addContactRec(first->tail, contact, groupDim, ok);//Tiene q seguir el caso rec
    return first; //cuando termina la ida empieza a devolver
}

int addContact(addressBookADT ab, const char * groupName, tContact contact) {
    int ok = 0;
    if ( groupName==NULL || contact.name==NULL ) {
        return 0; //Q no lo devolvio
    }
    tNodoG * foundGroup = findGroup( ab->firstGroup, groupName);
    if (foundGroup!=NULL) {//Si llego hasta aca puede agregar el contacto en la lista del grupo en su posicion(alfabeticamente)
        foundGroup->firstPerson=addContactRec(foundGroup->firstPerson, contact, &foundGroup->groupDim, &ok); //Q la funcion sea el valor izquierdo de lo q hay en el primer elemento de la lista de contactos ////
    }                                                                           //NO ES foundGroup->groupDim
    return ok; //Si no agrego es cero
}

//
// Permite iterar por todos los contactos de la agenda
// QUE PERTENEZCAN AL GRUPO INDICADO por parámetro en toBegin
// El orden es alfabético por nombre del contacto.
//
void toBeginForGroup(addressBookADT ab, const char * groupName) { //inicializa lo necesario para iniciar la iteracion
    tNodoG * start = findGroup( ab->firstGroup, groupName);
    if(start != NULL) {
        ab->currentPerson = start->firstPerson;
        return;
    }
    ab->currentPerson = NULL;
    // ab->currentGroup=start;
    // if (start!=NULL) {
    //     ab->currentPerson=start->firstPerson;
    // }
}

int hasNextForGroup(addressBookADT ab) { //Q en el grupo no se recorrio t.odo todavia
    return ab->currentPerson!=NULL;
}

// Retorna un contacto, aborta si no hay siguiente
tContact nextForGroup(addressBookADT ab) {
    if (!hasNextForGroup(ab)) {
        exit(1); //Q salga y me entero q es por eso
    }
    tContact aux = ab->currentPerson->person; //Q el elemento de la persona actual se actualize
    ab->currentPerson = ab->currentPerson->tail; //Q la persona actual se actualize(q pase a la sgte)
    return aux;
}

/*
** Permite iterar por todos los grupos de la agenda
** El orden es alfabético por nombre del grupo.
*/
void toBegin(addressBookADT ab) {
    ab->currentGroup=ab->firstGroup;
}

int hasNext(addressBookADT ab) {
    return ab->currentGroup!=NULL;
}

/* Retorna una copia del grupo, aborta si no hay siguiente */
char * next(addressBookADT ab) {
    if (!hasNext(ab)) { //NOTA: NO ES ab->currentGroup pq ya esta en hasNext
        exit(1);
    }
    char * ans = malloc(sizeof(char)*strlen(ab->currentGroup->groupName)+1);
    strcpy(ans, ab->currentGroup->groupName);
    ab->currentGroup=ab->currentGroup->tail;
    return ans;
}


