#include "multiSetADT.h"
#include <stdlib.h>
#define BLOCK   10

struct node {
    elemType elem;
    size_t elemCount;
    struct node *tail;
};

typedef struct node *tList;

struct multiSetCDT {
    tList list;
    size_t dim;
};


multiSetADT newMultiSet() {
    return calloc(1, sizeof(struct multiSetCDT));
}

tList addRec(tList l, elemType elem, size_t *flag, size_t *toReturn) {
    if(l == NULL) {
        tList new = malloc(sizeof(struct node));
        new->elem = elem;
        new->elemCount = 1;
        new->tail = NULL;
        *flag = 1;
        *toReturn = 1;
        return new;
    }
    if(compare(l->elem, elem) == 0) {
        *toReturn = ++l->elemCount;
        return l;
    }
    l->tail = addRec(l->tail, elem, flag, toReturn);
    return l;

}

unsigned int add(multiSetADT multiSet, elemType elem) {
    size_t flag = 0;
    size_t toReturn = 0;
    multiSet->list = addRec(multiSet->list, elem, &flag, &toReturn);
    multiSet->dim += flag;
    return toReturn;
}

unsigned int countRec(const tList l, elemType elem) {
    if(l == NULL) {
        return 0;
    }
    if(compare(l->elem, elem) == 0)
        return l->elemCount;
    return countRec(l->tail, elem);
}

unsigned int count(const multiSetADT multiSet, elemType elem) {
    return countRec(multiSet->list, elem);
}

unsigned int size(const multiSetADT multiSet) {
    return multiSet->dim;
}

static tList removeRecM(tList l, elemType elem, size_t *flag) {
    if(l == NULL) {
        return l;
    }
    if(compare(l->elem, elem) == 0) {
        *flag = --l->elemCount;
        return l;
    }
    l->tail = removeRecM(l->tail, elem, flag);
    return l;
}

int removeM(multiSetADT multiSet, elemType elem) {
    size_t flag = 0;
    multiSet->list = removeRecM(multiSet->list, elem, &flag);
    return flag;
}

tList removeAllRecM(tList l, elemType elem) {
    if(l == NULL) {
        return l;
    }
    if(compare(l->elem, elem) == 0) {
        tList aux = l->tail;
        free(l);
        return aux;
    }
    l->tail = removeAllRecM(l->tail, elem);
    return l;
}

void removeAllM(multiSetADT multiSet, elemType elem) {
    multiSet->list = removeAllRecM(multiSet->list, elem);
}

elemType * minElements(const multiSetADT multiSet, int * dim) {
    *dim = 0;
    tList aux = multiSet->list;
    elemType *toReturn = NULL;
    int max = aux->elemCount;
    for(int i=0; i<multiSet->dim; i++) {
        if(aux->elemCount <= max) {
            max = aux->elemCount;
            if(*dim % BLOCK == 0) {
                toReturn = realloc(toReturn, (*dim + BLOCK) * sizeof(elemType));
            }
            toReturn[*dim] = aux->elem;
            (*dim)++;
        }
        aux = aux->tail;
    }
    toReturn = realloc(toReturn, (*dim)*sizeof(elemType));
    return toReturn;
}

void freeMultiSetRec(tList l) {
    if(l == NULL) {
        return;
    }
    tList aux = l->tail;
    free(l);
    freeMultiSetRec(aux);
}

void freeMultiSet(multiSetADT m) {
    freeMultiSetRec(m->list);
    free(m);
}