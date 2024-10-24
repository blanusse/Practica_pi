#include "bagADT.h"
#include <stdlib.h>


struct node {
    elemType head; // elemento
    struct node *tail; // direccion al siguiente
    unsigned int count; // cantidad de veces que se repite el head
};

typedef struct node *tList; // tList es un puntero a nodo

struct bagCDT {
    tList first;
    unsigned int size;
};

static void freeList(tList l) {
    if(l == NULL)
        return;
    freeList(l->tail);
    free(l);
}

void freeBag( bagADT bag) {
    freeList(bag->first);
    free(bag);
}

bagADT newBag(compare cmp) {
    bagADT toReturn = malloc(sizeof(struct bagCDT));
    toReturn->first = NULL;
    toReturn->size = 0;
    return toReturn;
}

unsigned int add(bagADT bag, elemType elem);

unsigned int delete(bagADT bag, elemType elem);

unsigned int count(const bagADT bag, elemType elem);

unsigned int size(const bagADT bag);

elemType mostPopular(bagADT bag);