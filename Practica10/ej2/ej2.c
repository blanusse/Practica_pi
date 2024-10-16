#include <stdio.h>
#include "../../Lib/list.h"

tList deleteMio(tList l, int elem) {
    if(l == NULL || elem > l->head)
        return l;
    if(elem == l->head) {
        tList aux = l->tail;
        free(l);
        return aux;
    }
    l->tail = deleteMio(l->tail, elem);
    return l;
}


int get(tList l, unsigned int i) {
    int tam = size(l);
    if(i >= tam) {
        fprintf(stderr, "El indice es mayor a la cantidad de elementos");
        exit(1);
    }
    for(int k=0; k<i; k++) {
        l = l->tail;
    }
    return l->head;
}
