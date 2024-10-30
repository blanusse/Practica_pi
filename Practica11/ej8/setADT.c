#include "setADT.h"
#include <stdlib.h>

typedef struct tNode * tList;

struct tNode {
    elemType head;
    tList tail;
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

setADT unionSet(setADT set1, setADT set2) {
    int newDim = elemCount(set1->first) + elemCount(set2->first);
    setADT newSet = malloc(newDim * sizeof(struct setCDT));

}

setADT intersectionSet(setADT set1, setADT set2);

setADT diffSet(setADT set1, setADT set2);