#include "setADT.h"
#include <stdlib.h>

typedef struct tNode * tList;

struct tNode {
    elemType head;
    tList tail;
};

struct setCDT {
    tList first;
    int (*pFunc)(elemType, elemType); // elem type seria el tipo de variable que recibe la funcion
    unsigned int size;
};


static void freeList(tList l) {
    if(l == NULL)
        return;
    freeList(l->tail);
    free(l);

}
setADT newSet(int (*compare)(elemType, elemType)) {
    setADT toReturn = malloc(sizeof(struct setCDT));
    toReturn->first = NULL;
    toReturn->pFunc = compare;
    toReturn->size = 0;
    return toReturn;
}

void freeSet(setADT set) {
    freeList(set->first);
    free(set);
}

int isEmptySet(setADT set) {
    return set->size == 0;
}

int setContains(const setADT set, elemType element) {
    if(set->first == NULL)
        return 0;
    if(set->pFunc(element, set->first->head)) {
        return 1;
    }
    return setContains(set->first->tail, element);
}

int addElement(setADT set, elemType element) {
    set = realloc(set, set->size * sizeof(struct setCDT));

}

int deleteElement(setADT set, elemType element);

int sizeSet(const setADT set);

setADT unionSet(setADT set1, setADT set2);

setADT intersectionSet(setADT set1, setADT set2);

setADT diffSet(setADT set1, setADT set2)