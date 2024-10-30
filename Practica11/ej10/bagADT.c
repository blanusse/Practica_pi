#include "bagADT.h"
#include <stdlib.h>



typedef struct node {
    elemType head; // elemento
    struct node *tail; // direccion al siguiente
    unsigned int count; // cantidad de veces que se repite el head
}tNode;

typedef  tNode *tList; // tList es un puntero a nodo

struct bagCDT {
    tList first;
    unsigned int size;
    compare pFunc;
};



void freeBag( bagADT bag) {
    if(bag->first == NULL) {
        free(bag);
        return;
    }
    tList aux = bag->first;
    bag->first = bag->first->tail;
    free(aux);
    freeBag(bag);
}

bagADT newBag(compare cmp) {
    bagADT toReturn = calloc(1, sizeof(struct bagCDT));
    toReturn->pFunc = cmp;
    return toReturn;
}

tList addRec(tList actual, elemType elem, int *count, compare pFunc) {
    if(actual == NULL) {
        tList new = calloc(1, sizeof(tNode));
        *count = 1;
        new->count = 1;
        new->head = elem;
        return new;
    }
    if(!pFunc(actual->head, elem)) {
        *count = ++actual->count;
        return actual;
    }
    actual->tail = addRec(actual->tail, elem, count, pFunc);
    return actual;
}


unsigned int add(bagADT bag, elemType elem) { //se crea una func recursiva para poder devolver la direc del siguiente
    int count = 0;
    bag->first = addRec(bag->first, elem, &count, bag->pFunc);
    if(count == 1) {
        bag->size++;
    }
    return count;
}


tList deleteRec(tList actual, elemType elem, int *count, compare pFunc) {
    if(actual == NULL)
        return NULL;
    if(!pFunc(actual->head, elem)) {
        if(actual->count == 1) {
            *count = 0;
            tList aux = actual->tail;
            free(actual);
            aux->tail = deleteRec(aux->tail, elem, count, pFunc);
            return aux;
        }
        *count = --actual->count;
        return actual;
    }
    actual->tail = deleteRec(actual->tail,elem, count, pFunc);
    return actual;
}

unsigned int delete(bagADT bag, elemType elem){
    int count;
    bag->first = deleteRec(bag->first, elem, &count, bag->pFunc);
    if(count == 0) {
        bag->size--;
    }
    return count;
}

//devuelve el tNode que buscaba, en caso de que no este devuevle NULL
tList countRec(tList actual, elemType elem, compare pFunc) {
    if(actual == NULL)
        return NULL;
    if(!pFunc(actual->head, elem)) {
        return actual;
    }
    return countRec(actual->tail, elem, pFunc);
}

unsigned int count(const bagADT bag, elemType elem) {
    tList aux = countRec(bag->first, elem, bag->pFunc);
    if(aux == NULL)
        return 0;
    return aux->count;

}


unsigned int size(const bagADT bag) {
    return bag->size;
}

//Devuelve el tNode que mas se repite
tList mostPopularRec(tList actual) {
    int reps=0;
    tList aux = actual;
    for(;actual != NULL; actual = actual->tail) {
        if(actual->count > reps) {
            aux = actual; //guarda en el aux el tNode que mas se repite
            reps = actual->count; //cambia el mas popular
        }
    }
    return aux; // devuelve el que mas se repite



}

elemType mostPopular(bagADT bag) {
    if(bag->first == NULL)
        exit(1);
    tList popular = mostPopularRec(bag->first);
    if(popular ==NULL)
        return NULL;
    return popular->head;
}