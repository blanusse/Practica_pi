#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "../../Lib/utillist.h"



typedef int (*fn) (int);



tList depuraLista(tList l, int (*pFunc)(int)) {
    if(l==NULL)
        return l;
    if(pFunc(l->head)) {
        tList aux = l->tail;
        free(l);
        return depuraLista(aux, pFunc);
    }
    l->tail = depuraLista(l->tail, pFunc);
    return l;
}


int esImpar(int x) {
    return x % 2;
}

int esPositivo(int x) {
    return x > 0;
}

int esPar(int x) {
    return !esImpar(x);
}

int
main(void) {
    fn f = &esImpar;
    int v1[] = {4,3,7,2,6};
    tList l1 = fromArray(v1, 5);

    l1 = depuraLista(l1, f);
    int v1res[] = {4,2,6};
    assert(checkElems(l1, v1res, 3));
    freeList(l1);

    tList l2 = fromArray(v1, 5);
    assert(depuraLista(l2, esPositivo) == NULL);

    tList l3 = fromArray(v1, 5);
    l3 = depuraLista(l3, esPar);
    int v3res[] = {3,7};
    assert(checkElems(l3, v3res, 2));
    freeList(l3);

    printf("OK!\n");
    return 0;
}

