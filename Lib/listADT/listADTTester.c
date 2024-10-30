#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listADT.h"


int main() {
    listADT l = newList(strcmp);
    assert(isEmpty(l) == 1);
    assert(add(l, "Hola") == 1);
    assert(add(l, "Hola") == 0);
    assert(add(l, "abc") == 1);
    assert(elemCount(l) == 2);
    assert(belongs(l, "Hola") == 1);
    assert(belongs(l, "123") == 0);

    //Para leer todos los elementos
    //Opcion 1:
    //Duplica la lista a un vector (INEFICIENTE)
    char ** v = toArray(l);
    for(int i=0; i< elemCount(l); i++) {
        printf("%s\n", v[i]); // imprime todos los elementos del listADT
    }
    free(v);

    //Opcion 2:
    //Recorre desde el principio hasta el elemento que se pide con el indice (INEFICIENTE)
    for(int i=0; i<elemCount(l); i++) {
        printf("%s\n", getElemAtIndex(l, i));
    }
    //Opcion 3: (CORRECTA)
    //Solo un recorrido
    toBegin(l);
    while (hasNext(l)) {
        printf("%s\n", next(l));
    }

    freeList(l);



    puts("OK!");
}