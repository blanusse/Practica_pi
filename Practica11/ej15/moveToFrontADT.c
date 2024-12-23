#include "moveToFrontADT.h"
#include <stdlib.h>

struct tNode {
    elemType head;
    struct tNode *tail;
};

typedef struct tNode *tList;

struct moveToFrontCDT {
    tList first;
    tList current;
    compare pFunc;
    size_t dim;
};
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

moveToFrontADT newMoveToFront(compare cmp) {
    moveToFrontADT toReturn = calloc(1, sizeof(struct moveToFrontCDT));
    toReturn->pFunc = cmp;
    return toReturn;
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

static void freeMoveToFrontRec(tList list) {
    if(list == NULL)
        return;
    tList aux = list->tail;
    free(list);
    freeMoveToFrontRec(aux);
}

void freeMoveToFront(moveToFrontADT moveToFront) {
    freeMoveToFrontRec(moveToFront->first);
    free(moveToFront);
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

static tList addRec(tList list, elemType elem, int *added, compare pFunc) {
    if(list == NULL) { //la lista esta vacia, entonces agrego o se llego al final
        tList new = malloc(sizeof(struct tNode));
        new->head = elem;
        new->tail = NULL;
        (*added)++;
        return new;
    }
    if(pFunc(list->head, elem) == 0) { // ya esta en la lista
        return list;
    }
    list->tail = addRec(list->tail, elem, added, pFunc);
    return list;
}

unsigned int add(moveToFrontADT moveToFront, elemType elem) {
    int added = 0;
    moveToFront->first = addRec(moveToFront->first, elem, &added, moveToFront->pFunc);
    moveToFront->dim+=added;
    return added;

}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

unsigned int size(moveToFrontADT moveToFront) {
    return moveToFront->dim;
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

void toBegin(moveToFrontADT moveToFront) {
    moveToFront->current = moveToFront->first;
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

int hasNext(moveToFrontADT moveToFront) {
    return moveToFront->current != NULL;
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

elemType next(moveToFrontADT moveToFront) {
    if(hasNext(moveToFront)) {
        elemType aux = moveToFront->current->head;
        moveToFront->current = moveToFront->current->tail;
        return aux;
    }
    exit(1);
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

//funcion que busca el get y lo elimina
static tList getRec(tList list, elemType elem,  compare pFunc, tList *found) {
    if(list == NULL) { //significa que no lo encontro
        *found = NULL;
        return NULL;
    }
    if(pFunc(list->head, elem) == 0) { //lo encontro
        *found = list;
        return list->tail;
    }
    list->tail = getRec(list->tail, elem, pFunc, found);
    return list;

}

elemType * get(moveToFrontADT moveToFront, elemType elem) {

    tList found; //almacenara si encuentra el elemento
    moveToFront->first = getRec(moveToFront->first, elem, moveToFront->pFunc, &found); //nueva lista sin el elemento buscado si se encontro,
                                                                                // sino es la misma lista
    if(found != NULL) {
        found->tail = moveToFront->first;
        moveToFront->first = found;
        elemType *toReturn = malloc((sizeof(elemType)));
        *toReturn = found->head;
        return toReturn;
    }
    return NULL;


}


