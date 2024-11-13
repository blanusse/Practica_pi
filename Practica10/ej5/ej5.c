#include <stdio.h>
#include <stdlib.h>
#include "../../Lib/utillist.h"
#include <assert.h>
#define ELEMS 200

tList restaList(tList lista1, tList lista2) {
    if (lista1 == NULL){
        return NULL;
    }
    if (lista2 == NULL || lista1->head < lista2->head){
        tList aux = malloc(sizeof(tNode));
        aux->head = lista1->head;
        aux-> tail = restaList(lista1->tail, lista2);
        return aux;
    }
    if (lista1->head > lista2->head){
        return restaList(lista1, lista2->tail);
    }
    // Son iguales
    return restaList(lista1->tail, lista2->tail);
}



int main(void) {
    int pares[ELEMS], impares[ELEMS];

    for(int i=1; i <= ELEMS; i++) {
        pares[i-1] = i * 2 ;
        impares[i-1] = i * 2 - 1;
    }

    tList lPar = fromArray(pares, ELEMS);
    tList lImpar = fromArray(impares, ELEMS);

    tList lPar2 = restaList(lPar, lImpar);
    assert(checkElems(lPar2, pares, ELEMS));
    // Verificamos ademas que no sean los mismos nodos
    assert(lPar2 != lPar);
    assert(lPar2->tail != lPar->tail);
    freeList(lPar2);
    freeList(lPar);
    freeList(lImpar);

    int all[ELEMS * 2];
    for(int i=1, j=0; i <= ELEMS; i++) {
        all[j++] = i * 2 - 1;
        all[j++] = i * 2 ;
    }
    tList lAll = fromArray(all, ELEMS * 2);
    lPar = fromArray(pares, ELEMS);
    tList lImpar2 = restaList(lAll, lPar);
    assert(checkElems(lImpar2, impares, ELEMS));
    freeList(lPar);

    lPar = restaList(lAll, lImpar2);
    assert(checkElems(lPar, pares, ELEMS));
    freeList(lPar);
    freeList(lAll);

    lPar = NULL;
    lImpar = fromArray(impares, ELEMS);
    tList aux = restaList(lPar, lImpar);
    assert(aux == NULL);
    freeList(lImpar);

    aux = restaList(lImpar2, lImpar2);
    assert(aux == NULL);
    freeList(lImpar2);

    printf ("OK!\n");
    return 0;
}