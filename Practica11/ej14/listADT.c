#include "listADT.h"

#include <stdlib.h>

struct tNode {
    elemType head;
    struct tNode *tail;
    size_t index;
    size_t indexAsc;
};

typedef struct tNode *tList;

struct listCDT {
    int (*pFunc) (elemType e1, elemType e2);
    tList first;
    size_t dim;
    tList current;
    tList currentAsc;
};

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

listADT newList(int (*compare) (elemType e1, elemType e2)) {
    listADT toReturn = calloc(1, sizeof(struct listCDT));
    toReturn->pFunc = compare;
    return toReturn;
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
static tList addRec(tList first, elemType elem, cmp compare, size_t dim, int *flag) {
    int c;
    if(first == NULL || (c = compare(elem, first->head)) < 0) {
        tList newNode = malloc(sizeof(struct tNode));
        newNode->head = elem;
        newNode->tail = first;
        (*flag)++;
        newNode->index = dim+1;
        if(first == NULL) {
            newNode->indexAsc = dim+1;
        }
        else {
            first->indexAsc++; // pq el nuevo nodo se posiciona atras
            newNode->indexAsc = (first->indexAsc)-1;
        }
        return newNode;
    }
    if(c == 0) {
        return first;
    }
    first->tail = addRec(first->tail, elem, compare,dim, flag);
    return first;
}


void add(listADT list, elemType elem) {
    int flag = 0;
    list->first = addRec(list->first, elem, list->pFunc, list->dim, &flag);
    list->dim += flag;
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

static tList deleteRec(tList first, elemType elem, cmp compare, int *flag) {
    int c;
    if(first == NULL || (c = compare(elem, first->head)) < 0) { //no lo encontro, entonces termino de recorrer
        return first;
    }
    if(c == 0) { //significa que lo encontro
        tList aux = first->tail;
        free(first);
        (*flag)++;
        return aux;
    }
    first->tail = deleteRec(first->tail, elem, compare, flag);
    return first;
}

void delete(listADT list, elemType elem) {
    int flag = 0;
    list->first = deleteRec(list->first, elem, list->pFunc, &flag);
    list->dim-=flag;
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

static tList toBeginRec(tList first) {
    if(first == NULL) {
        return NULL;
    }
    if(first->index == 1) { // si encontro el que tiene indice =1 devuelve un puntero a ese nodo
        return first;
    }
    return toBeginRec(first->tail); //sigue con el proximo
}

void toBegin(listADT list) {
    list->current = toBeginRec(list->first);
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

static int hasNextRec(tList list, int indexAct){
    if(list == NULL)
        return 0;
    if(list->index > indexAct) {
        return 1;
    }
    hasNextRec(list->tail, indexAct);

}

int hasNext(listADT list){
    if(list->current == NULL)
        return 0;
    int indexAct = list->current->index;
    return hasNextRec(list->first, indexAct);

}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

static tList nextRec (tList list, int actIdx){
    //como se asegura que tiene siguiente no hace falta el caso en el que list == NULL
    if(list->index == actIdx+1) {
        return list;
    }
    return nextRec(list->tail, actIdx);
}

elemType next(listADT list){
    if(hasNext(list) == 0)
        return list->current->head;
    int actIdx = list->current->index;
    int toReturn = list->current->head;
    list->current = nextRec(list->first, actIdx);
    return toReturn;

}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------


void toBeginAsc(listADT list){
    list->currentAsc = list->first;
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

int hasNextAsc(listADT list){
    if(list->currentAsc == NULL)
        return 0;
    return list->currentAsc->tail != NULL;
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

elemType nextAsc(listADT list){
    if(hasNextAsc(list) == 0)
        return list->currentAsc->head;
    int toReturn = list->currentAsc->head;
    list->currentAsc = list->currentAsc->tail;
    return toReturn;
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

void freeListRec(tList list){
    if(list == NULL)
        return;
    tList aux = list->tail;
    free(list);
    freeListRec(aux);
}

void freeList(listADT list){
    freeListRec(list->first);
    free(list);
}




