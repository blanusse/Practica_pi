#include "setADT.h"
#include <stdlib.h>

typedef struct tNode * tList;

struct tNode {
    elemType head;
    tList tail;
};
struct listCDT {
    tList first; //direccion del primer nodo de la lista
    size_t dim; //elementos de la lista
    cmp pFunc; //puntero a funcion que compara si dos elemType son iguales o no y retorna 1 o 0
    tList current; // para funciones de iteracion
};
struct setCDT {
    listADT first;
};


setADT newSet(int (*compare)(elemType, elemType)) {
    setADT toReturn = malloc(sizeof(struct setCDT));
    toReturn->first = newList(*compare);

    return toReturn;

}

void freeSet(setADT set) {
    freeList(set->first);
    free(set);
}

int isEmptySet(setADT set) {
    return isEmpty(set->first);
    set->first->
}

int setContains(const setADT set, elemType element) {
    return belongs(set->first, element);
}

int addElement(setADT set, elemType element) {
    return add(set->first, element);
}

int deleteElement(setADT set, elemType element) {
    return delete(set->first, element);
}

int sizeSet(const setADT set) {
    return elemCount(set->first);
}

static setADT unionSetRec(listADT set1, listADT set2) {
}

setADT unionSet(setADT set1, setADT set2) {
    if(set1 == NULL) {
        return set2;
    }
    if(set2 == NULL)
        return set1;
    setADT toReturn = NULL;
    toBegin(set1->first);
    toBegin(set2->first);

    unionSetRec(set1->first, set2->first);

}

setADT intersectionSet(setADT set1, setADT set2) {

}

setADT diffSet(setADT set1, setADT set2) {

}