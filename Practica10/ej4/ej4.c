#include <stdio.h>
#include "../../Lib/utillist.h"
#include <assert.h>
#include <stdlib.h>
#define ELEMS 200



tList addAll(tList l1, tList l2) {
    if(l2==NULL)
        return l1;
    if(l1==NULL || l1->head > l2->head) {
        tList aux = malloc(sizeof(tNode));
        aux->head = l2->head;
        aux->tail = addAll(l1, l2->tail);
        return aux;
    }

    if(l1->head < l2->head) {
        l1->tail = addAll(l1->tail, l2);
        return l1;
    }
    if(l1->head == l2->head) {
        l1->tail = addAll(l1->tail, l2->tail); // Esto sirve para no perder la direccion del primer elemento de la lista
        return l1;
    }


}


int main(void) {

    int pares[ELEMS], impares[ELEMS];

    for(int i=1; i <= ELEMS; i++) {
        pares[i-1] = i * 2 ;
        impares[i-1] = i * 2 - 1;
    }

    tList lPar = fromArray(pares, ELEMS);
    tList lImpar = fromArray(impares, ELEMS);

    lPar = addAll(lPar, lImpar);

    int all[ELEMS * 2];
    for(int i=1, j=0; i <= ELEMS; i++) {
        all[j++] = i * 2 - 1;
        all[j++] = i * 2 ;
    }
    assert(checkElems(lPar, all, ELEMS*2));
    freeList(lPar);

    lPar = NULL;
    lPar = addAll(lPar, lImpar);
    assert(checkElems(lPar, impares, ELEMS));

    lPar = addAll(lPar, lImpar);
    assert(checkElems(lPar, impares, ELEMS));
    freeList(lPar);

    lPar = fromArray(pares, ELEMS);
    lImpar = addAll(lImpar, lPar);
    assert(checkElems(lImpar, all, ELEMS*2));
    freeList(lPar);
    freeList(lImpar);

    int w[] = {1,2,3,4,5,6,7,8};
    tList l1 = fromArray(w,3);
    tList l2 = fromArray(w+3,5);
    l1 = addAll(l1,l2);
    assert(checkElems(l1, w, 8));
    freeList(l1);
    freeList(l2);

    l1 = fromArray(w,8);
    l2 = fromArray(w,8);
    l1 = addAll(l1,l2);
    assert(checkElems(l1, w, 8));
    freeList(l2);
    freeList(l1);


    printf ("OK!\n");
    return 0;
}