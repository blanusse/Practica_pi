#include "adressBookADT.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef struct nodoPerson {
    tContact person;
    struct nodoPerson *tail;
}nodoPerson;

typedef nodoPerson *tContactsGroups;

struct tGroup {
    char *groupName; //nombre del grupo
    tContactsGroups list; // lista de contactos del grupo
    size_t groupDim; //cantidad de contactos del grupo
    struct tGroup *nextGroup; //puntero a siguiente grupo, ordenado alfabeticamente
};

typedef struct tGroup *tPhone;

struct addressBookCDT {
    tPhone firstGroup; //puntero a primer grupo
    tPhone currentGroup; //iterador para grupos
    tContactsGroups currentPerson; //iterador para ersonas dentro de grupos
    size_t groupCount; //cantidad de grupos
};
//------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

addressBookADT newAddressBook() {
    return calloc(1, sizeof(struct addressBookCDT));
}

//------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

tPhone addGroupRec(tPhone firstGroup , const char * groupName, int *flag) {
    int c;
    if(firstGroup == NULL ||(c = strcasecmp(groupName, firstGroup->groupName)) < 0) { // significa que no lo encontro o ya se paso del lugar donde deberia estar
        tPhone newGroup = calloc(1, sizeof(struct tGroup));
        int tam = strlen(groupName); // tamaño del nombre de grupo
        newGroup->groupName = realloc(newGroup->groupName, sizeof(char)*(tam+1));
        strcpy(newGroup->groupName, groupName);
        newGroup->nextGroup = firstGroup;
        *flag = 1;
        return newGroup;
    }
    if(c == 0) { //significa que lo encontro, entonces devuelve la misma lista de grupos
        return firstGroup;
    }
    firstGroup->nextGroup = addGroupRec(firstGroup->nextGroup, groupName, flag);
    return firstGroup;
}

int addGroup(addressBookADT phone, const char * groupName) {
    if(groupName == NULL)
        return 0;
    int flag = 0;
    phone->firstGroup = addGroupRec(phone->firstGroup, groupName, &flag);
    phone->groupCount+=flag;
    return flag;
}
//------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

tContactsGroups addContactRec(tContactsGroups personList, tContact contact, size_t *groupDim, int *flag) {
    int c;
    if(personList == NULL || (c = strcasecmp(contact.name, personList->person.name)) < 0){
        tContactsGroups newContact = malloc(sizeof(nodoPerson)*(*groupDim + 1));
        newContact->person = contact;
        newContact->tail = personList;
        (*groupDim)++;
        (*flag) = 1;
        return newContact;
    }
    if(c == 0) { //ya existe ese nombre en este grupo
        return personList;
    }
    personList->tail = addContactRec(personList->tail, contact, groupDim, flag);
    return personList;
}

//funcion que busca el grupo y lo devuelve
tPhone searchGroup(tPhone actualGroup, const char * groupName) {
    int c;
    if(actualGroup == NULL || (c = strcasecmp(groupName, actualGroup->groupName)) < 0) { //no encontro el grupo
        return NULL;
    }
    if(c == 0) { //encontro el grupo
        return actualGroup;
    }
    return searchGroup(actualGroup->nextGroup, groupName);
}

int addContact(addressBookADT phone, const char * groupName, tContact contact) {
    if(groupName == NULL)
        return 0;
    tPhone toAdd = searchGroup(phone->firstGroup, groupName);
    if(toAdd == NULL)
        return 0;
    int flag = 0;
    toAdd->list = addContactRec(toAdd->list, contact, &toAdd->groupDim, &flag);
    return flag;

}
//------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

void toBeginForGroup(addressBookADT phone, const char * groupName) {
    tPhone foundGroup = searchGroup(phone->firstGroup, groupName);
    if(foundGroup != NULL) {
        phone->currentPerson = foundGroup->list;
    }
}
//------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

int hasNextForGroup(addressBookADT phone) {
    return phone->currentPerson != NULL;
}
//------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

tContact nextForGroup(addressBookADT phone) {
    assert(hasNextForGroup(phone));
    tContact toReturn = phone->currentPerson->person;
    phone->currentPerson = phone->currentPerson->tail;
    return toReturn;
}
//------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

void toBegin(addressBookADT phone) {
    phone->currentGroup = phone->firstGroup;
}
//------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

int hasNext(addressBookADT phone) {
    return phone->currentGroup != NULL;
}
//------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

char * next(addressBookADT phone) {
    assert(hasNext(phone));
    char * toReturn = malloc(sizeof(char) * (strlen(phone->currentGroup->groupName) + 1));
    strcpy(toReturn, phone->currentGroup->groupName);
    phone->currentGroup = phone->currentGroup->nextGroup;
    return  toReturn;
}

//------------------------------------------------------//////\\\\\\-------------------------------------------------------------------





