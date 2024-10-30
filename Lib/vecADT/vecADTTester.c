#include "vecADT.h"
#include <stdio.h>
#include <assert.h>

int main() {
    vecADT v =newVec();
    assert(elemCount(v) == 0);
    //agrego el nro 1000 en la posicion 12
    putElem(v, 12, 1000);

    //obtengo el elemento en la posicion 12
    elemType aux;
    assert(getElem(v, 12, &aux) && aux == 1000);

    putElem(v, 20, 300);
    putElem(v, 3, 100);

    assert(elemCount(v) == 3);
    assert(getElem(v, 20, &aux) && aux == 300);
    assert(getElem(v, 3, &aux) && aux == 100);
    assert(getElem(v, 5, &aux) == 0);
    free(v);
    puts("OK!");
}