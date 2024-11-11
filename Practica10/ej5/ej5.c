#include <stdio.h>
#include "../../Lib/utillist.h"
#include <stdlib.h>
#include <assert.h>
#define ELEMS 200

tList restaList(tList l1, tList l2) {
    if(l1 == NULL || l2 == NULL)
        return l1;

    if(l1->head == l2->head) {
        tList aux = l1->tail;
        free(l1);
        return restaList(aux, l2->tail);
    }
    if(l1->head > l2->head) {
        l1->tail = restaList(l1, l2->tail);
        return l1;
    }
    l1->tail = restaList(l1->tail, l2);
    return l1;
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