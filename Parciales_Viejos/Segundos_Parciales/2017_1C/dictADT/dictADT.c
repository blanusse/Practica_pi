#include "dictADT.h"
#include <stdlib.h>
#include <string.h>

struct tElem {
    elemType elem; //elemento
    int key; //clave
    struct tElem *tail; //puntero a siguiente elemento
};
typedef struct tElem *tElemList;

struct dictCDT {
    tElemList list; //lista de elementos con clave unica
    size_t elemCount; //cantidad de elementos con clave unica
};


dictADT newDict() {
    return calloc(1, sizeof(struct dictCDT));
}

void freeDictRec(tElemList l) {
    if(l == NULL) {
        return;
    }
    tElemList aux = l->tail;
    free(l);
    freeDictRec(aux);
}

void freeDict (dictADT m ) {
    freeDictRec(m->list);
    free(m);
}

tElemList addKeyRec(tElemList l, int key, const elemType value) {
    int c;
    if(l == NULL || (c = key - l->key) < 0) {
        tElemList aux = malloc(sizeof(struct tElem));
        aux->elem = value;
        aux->tail = l;
        aux->key = key;
        return aux;
    }
    if(c == 0) {
        l->elem = value;
        return l;
    }
    l->tail = addKeyRec(l->tail, key, value);
    return l;
}

void addKey(dictADT d, int key, const elemType value) {
    d->list = addKeyRec(d->list, key, value);
}

elemType getValueRec (tElemList l, const int key) {
    int c;
    if(l == NULL || (c = key - l->key) < 0) {
        return NULL;
    }
    if( c == 0)
        return l->elem;
    return getValueRec(l->tail, key);
}

elemType getValue (dictADT d, const int key) {
    return getValueRec(d->list, key);
}

int * keys (dictADT d) {

}