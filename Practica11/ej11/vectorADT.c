#include "vectorADT.h"
#define BLOCK   10
#include <stdlib.h>

typedef struct{
    elemType head; //elemento de la celda
    int isUsed; // esta vacio = 0 // esta usado = 1
} tElem;

struct vectorCDT{
    tElem * vec; //vector
    size_t size; //tamaño del vector (contando los espacios vacios)
    size_t count; //elementos en uso en el vector
    int (*Pfunc)(elemType source, elemType target); //funcion que compara
};


vectorADT newVector(int (*compare)(elemType source, elemType target)) {
    vectorADT toReturn = calloc(1, sizeof(struct vectorCDT));
    toReturn->Pfunc = compare;
    return toReturn;
}

void freeVector(vectorADT v) {
    free(v->vec);
    free(v);
}

size_t put(vectorADT v, elemType * elems, size_t dim, size_t index) {
    if(dim == 0)
        return 0;
    int new =0;
    int aux = index + dim; //espacio requerido para pegar el nuevo vector a partir del indice
    if(aux > v->size) { //me fijo si entra t.odo el vector nuevo a partir del indice
        v->vec = realloc(v->vec, aux*sizeof(tElem));
        for(int i=v->size; i < aux; i++) { // aclaro que todos los nuevos espacios estan vacios
            v->vec[i].isUsed = 0;
        }
        v->size = aux;
    }
    for(int i=index; i<aux && new < dim; i++) {
        if(v->vec[i].isUsed == 0) {
            v->vec[i].head = elems[new++];
            v->vec[i].isUsed = 1;
            v->count++;
        }
    }
    return new;
}



int getIdx(vectorADT v, elemType elem) {
    int i=0, found = 0;
    for(;!found && i<v->size; i++) {
        elemType aux = v->vec[i].head;
        if(v->vec[i].isUsed == 1 && !v->Pfunc(elem,aux)) { // si esta ocupado y es igual
            found = 1;
        }
    }
    if(found)
        return i-1;
    return -1;
}

void deleteElement(vectorADT v, size_t index) {
    if(index >= v->size || v->vec[index].isUsed == 0)
        return;
    v->vec[index].isUsed = 0;
    v->count--;
}

int elementCount(vectorADT v) {
    return v->count;
}
