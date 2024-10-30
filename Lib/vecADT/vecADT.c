#include "vecADT.h"



typedef struct elem {
    elemType elem;
    char isOcuppied;
}tElem;

typedef tElem * tList;

struct vecCDT {
    tList elems;
    size_t elemCount; //elementos en uso
    size_t size; //tamaño del vector
};






vecADT newVec(void) {
    return calloc(1, sizeof(struct vecCDT));
}

void putElem(vecADT v, size_t index, elemType elem) {
    if(index >= v->size ) {
        v->elems = realloc(v->elems, sizeof(tElem)*(index+1));
        for(int i=v->size; i<=index; i++) {
            v->elems[i].isOcuppied = 0;
        }
        v->size = index + 1 ;
    }
    v->elems[index].elem = elem;
    v->elems[index].isOcuppied = 1;
    v->elemCount++;
}

int getElem(vecADT v, size_t index, elemType* output) {
    int found = 0;
    if(index < v->size) {
        if(v->elems[index].isOcuppied == 1) {
            *output = v->elems[index].elem;
            found = 1;
        }
    }
    return found;
}

int removeElem(vecADT v, size_t index) {
    int deleted = 0;
    if(index < v->size) {
        if(v->elems[index].isOcuppied == 1) {
            v->elems[index].isOcuppied = 0;
            deleted = 1;
            v->elemCount--;
        }
    }
    return deleted;
}

int elemCount(vecADT v) {
    return v->elemCount;
}

void freeVec(vecADT v) {
    free(v->elems);
    free(v);
}