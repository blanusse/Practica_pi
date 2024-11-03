#include "socialADT.h"
#define MAX     21


struct tRelated {
    char name[MAX];
    struct tRelated *tail;
};

typedef struct tRelated *tPeopleRelated;


struct tPerson {
    char name[MAX];
    tPeopleRelated related;
    size_t cantRelated;
    struct tPerson *tail;
};
typedef struct tPerson *tPeople;

struct socialCDT {
    tPeople first;
    size_t dim;
};

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

socialADT newSocial() {
     return calloc(1, sizeof(struct socialCDT));

}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
void freeSocialRec2(tPeopleRelated relatedList) {
    if(relatedList == NULL)
        return;
    tPeopleRelated aux = relatedList->tail;
    free(relatedList);
    freeSocialRec2(aux);
}

void freeSocialRec(tPeople peopleList) {
    if(peopleList == NULL) {
        return;
    }
    freeSocialRec2(peopleList->related);
    tPeople aux = peopleList->tail;
    free(peopleList);
    freeSocialRec(aux);
}

void freeSocial(socialADT soc) {
    freeSocialRec(soc->first);

    free(soc);
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

static tPeople addPersonRec(tPeople people, const char * name, int *flag) {
    int comp;
    if(people == NULL || (comp = strcmp(people->name, name)) >= 0) { //encontro el lugar para que quede ordenado
        tPeople newPerson = malloc(sizeof(struct tPerson));
        newPerson->tail = people;
        newPerson->cantRelated = 0;
        newPerson->related = NULL;
        strncpy(newPerson->name, name, MAX);
        (*flag)++;
        return newPerson;
    }
    if(strcmp(people->name, name) == 0) {
        return people;
    }
    people->tail = addPersonRec(people->tail, name, flag);
    return people;
}

void addPerson(socialADT soc, const char * name) {
    if(name == NULL)
        return;
    int flag = 0;
    soc->first = addPersonRec(soc->first, name, &flag);
    soc->dim+=flag;
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

static tPeopleRelated addRelatedRec(tPeopleRelated relatedList, const char * related) {
    int comp;
    if(relatedList == NULL || (comp = strcmp(relatedList->name, related)) >=0 ) { //encotro el lugar para colocar el nombre en orden alfabetico
        tPeopleRelated newRel = malloc(sizeof(struct tRelated));
        strncpy(newRel->name, related, MAX);
        newRel->tail = relatedList;
        return newRel;
    }
        relatedList->tail = addRelatedRec(relatedList->tail, related);
    return relatedList;
}

static void searchName(tPeople personList, const char * name, const char * related) {
    if(personList == NULL) // significa que no encontro el nombre
        return;
    if(strcmp(personList->name, name) == 0) { //encontro el nombre de la persona, entonces va a agregar el related
        personList->related = addRelatedRec(personList->related, related);
        personList->cantRelated++;
    }
    return searchName(personList->tail, name, related); //avanza al siguiente nombre
}

void addRelated(socialADT soc, const char * name, const char * related) {
    if(name == NULL || related == NULL)
        return;
    searchName(soc->first, name, related);
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
static char ** relatedMakeVec(const tPeopleRelated relatedList, int dimRelatedList) {
    char **toReturn = malloc(sizeof(char*)*(dimRelatedList + 1)); //crea el vector con los lugares necesarios
    for(int i=0; i<dimRelatedList; i++) {
        toReturn[i] = malloc(MAX*sizeof(char));
    }
    tPeopleRelated aux = relatedList; //crea un puntero auxiliar a la lista de related
    for(int i=0; i<dimRelatedList; i++, aux=aux->tail) {
        strcpy(toReturn[i], aux->name); //copia el nombre apuntado por el puntero auxiliar en el vector
    }
    toReturn[dimRelatedList] = NULL;
    return toReturn;

}

static char **relatedFindName(tPeople peopleList, const char * person) {
    if(peopleList == NULL) // significa que no encontro a la persona
        return calloc(1, sizeof(char*));
    if(strcmp(peopleList->name, person) == 0) {     // encontro a la persona
        if(peopleList->cantRelated > 0) {
            return relatedMakeVec(peopleList->related, peopleList->cantRelated);
        }
        return calloc(1, sizeof(char*));//no tiene related
    }
    return relatedFindName(peopleList->tail, person);
}

char ** related(const socialADT soc, const char * person) {
    if(person == NULL)
        return calloc(1, sizeof(char*));
    return relatedFindName(soc->first, person);
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

char ** persons(const socialADT soc) {
    if(soc->first ==NULL)
        return calloc(1, sizeof(char*));
    char **toReturn = malloc(sizeof(char *) * (soc->dim + 1));
    for(int i=0; i<soc->dim+1; i++) {
        toReturn[i] = malloc(MAX*sizeof(char));
    }
    tPeople aux = soc->first;
    for(int i=0; i<soc->dim; i++) {
        strncpy(toReturn[i], aux->name, MAX);
        aux = aux->tail;
    }
    toReturn[soc->dim] = NULL;
    return toReturn;
}

