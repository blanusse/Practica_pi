#include "listADT.h"

#include <assert.h>
#include <stdlib.h>
#define BLOCK 10

// CDT de listas generico
//ordenado sin repetir

struct node {
    elemType head;
    struct node *tail;
};
typedef struct node *tList;


struct listCDT {
    tList first; //direccion del primer nodo de la lista
    size_t dim; //elementos de la lista
    cmp pFunc; //puntero a funcion que compara si dos elemType son iguales o no y retorna 1 o 0
    tList current; // para funciones de iteracion
};

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

listADT newList(cmp compare) {
    listADT toReturn = malloc( sizeof(struct listCDT));
    toReturn->dim = 0;
    toReturn->first = NULL;
    toReturn->pFunc = compare;
    return toReturn;
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

int elemCount(listADT l) {
    return l->dim;
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

int isEmpty(listADT l) {
    return l->dim == 0;
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

static int belongsRec(tList l, elemType elem, cmp pFunc ) {
    if(l == NULL)
        return 0;
    if(pFunc(l->head, elem) == 0) {
        return 1;
    }
    return belongsRec(l->tail, elem, pFunc);
}
int belongs(const listADT l, elemType elem) {

    return belongsRec(l->first, elem, l->pFunc);
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

static tList addRec(tList l, elemType elem, cmp pFunc, int *count) {
    int c;
    if(l==NULL || (c = pFunc(elem, l->head)) < 0) {
        tList aux = malloc(sizeof(struct node));
        aux->head = elem;
        aux->tail = l;
        (*count)++;
        return aux;
    }
    if(c == 0) {
        return l;
    }
    l->tail = addRec(l->tail, elem, pFunc, count);
    return l;
}

int add(listADT l, elemType elem) {
    int count = 0; // flag para ver si se arreglo
    l->first = addRec(l->first, elem, l->pFunc, &count);
    l->dim += count; // suma a la dimension si se agrego
    return count;

}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

tList deleteRec(tList l, elemType elem, cmp pFunc, int *flag) {
    int c;
    if(l == NULL || (c = pFunc(elem, l->head)) < 0)
        return l;
    if(c == 0) {
        tList aux = l->tail;
        free(l);
        (*flag)++;
        return aux;
    }
    l->tail = deleteRec(l->tail, elem, pFunc, flag);
    return l;
}

int delete(listADT l, elemType elem){
    int deleted = 0;
    l->first = deleteRec(l->first, elem, l->pFunc, &deleted);
    l->dim -= deleted;
    return deleted;
}

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------


static void freeListRec(tList l) {
    if(l == NULL)
        return;
    freeListRec(l->tail);
    free(l);
}


void freeList(listADT l) {
    freeListRec(l->first);
    free(l);
}

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

elemType *toArray(const listADT l) {
    if(l->dim == 0)
        return NULL;
    elemType *toReturn = malloc(l->dim * sizeof(elemType));
    tList aux = l->first;
    for(int i=0; i<l->dim; i++, aux = aux->tail) {
        toReturn[i] = aux->head;
    }
    return toReturn;
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

static elemType getElemAtIndexRec( tList l, int index) {
    if(index == 0) {
        return l->head;
    }
    return getElemAtIndexRec(l->tail, index-1);

}

elemType getElemAtIndex(const listADT l, int index) {
    assert(index >= 0 && index < l->dim); // chequea que el indice puesto sea valido
    return getElemAtIndexRec(l->first, index);

}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
elemType * select(listADT l, int (*pFunc)(elemType), int *dimRes) {
    elemType *toReturn = NULL;
    tList aux = l->first;
    *dimRes = 0;
    if(aux == NULL) {
        return NULL;
    }
    while(aux!= NULL) {
        if(pFunc(aux->head)) {
            if(*dimRes%BLOCK == 0) {
                toReturn = realloc(toReturn, (*dimRes+BLOCK)*sizeof(elemType));
            }
            toReturn[(*dimRes)++] = aux->head;
        }
        aux = aux->tail;
    }
    toReturn = realloc(toReturn, *dimRes*sizeof(elemType));
    return toReturn;
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
//EJERCICIO DE LA GUIA
void mapRec(tList l, elemType (*funcion)(elemType)) {
    if(l==NULL)
        return;
    l->head = funcion(l->head);
    mapRec(l->tail, funcion);
}

void map(listADT l, elemType (*funcion)(elemType)) {
    if(l->dim == 0)
        return;
    mapRec(l->first, funcion);
}


//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
//FUNCIONES DE ITERACION

void toBegin(listADT l) {
    l->current = l->first; // setea el current en el first
}

int hasNext(const listADT l) {
    return l->current != NULL; // si el current no es NULL significa que se puede leer el actual
}

elemType next(listADT l) {
    assert(hasNext(l));
    elemType toReturn = l->current->head; // se guarda el elemento del nodo actual
    l->current = l->current->tail; // se mueve al siguiente elemento (puede ser NULL)
    return toReturn;
}
