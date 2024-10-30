#include "../../Lib/listADT/listADT.h"
#include <stdlib.h>


struct node {
    elemType head;
    struct node *tail;
};
typedef struct node *tList;

struct listCDT {
    tList first; //direccion del primer nodo de la lista
    size_t dim; //elementos de la lista
    cmp pFunc; //puntero a funcion que compara si dos elemType son iguales o no y retorna 1 o 0
    tList current; // para funciones de iteracion
};


void mapRec(tList l, elemType (*funcion)(elemType)) {
    if(l==NULL)
        return;
    l->head = funcion(l->head);
    mapRec(l->tail, funcion);
}

void map(listADT l, elemType (*funcion)(elemType)) {
    if(l->dim == 0)
        return;
    mapRec(l->first, funcion);
}