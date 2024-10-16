#include <stdio.h>
#include <assert.h>
#include "../../lib/list.h"

tList listIntersec(tList l1, tList l2) {
    if(l1 == NULL || l2==NULL) {
        return NULL;
    }
    tList newList = malloc(sizeof(tNode));
    if(l1->head > l2->head) {
        newList->tail = listIntersec(l1, l2->tail);
        return newList;
    }
    if(l1->head < l2->head) {
        newList->tail = listIntersec(l1->tail, l2);
        return newList;
    }
    tList aux = malloc(sizeof(tNode));

}


int main(void) {

    int v[] = {1, 4, 5, 6, 7, 8};
    int w[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x[] = {2, 3, 9};

    tList l1 = fromArray(v, 6);
    tList l2 = fromArray(w, 9);
    tList l3 = listIntersec(l1, l2);
    assert(checkElems(l3, v, 6));
    assert(checkElems(l1, v, 6));
    assert(checkElems(l2, w, 9));
    freeList(l3);

    l3 = listIntersec(l2, l1);
    assert(checkElems(l3, v, 6));
    freeList(l3);

    l3 = listIntersec(l2, l2);
    assert(checkElems(l3, w, 9));
    freeList(l3);

    l3 = listIntersec(l2, NULL);
    assert(l3==NULL);
    l3 = listIntersec(NULL, l1);
    assert(l3==NULL);
    l3 = listIntersec(NULL, NULL);
    assert(l3==NULL);
    freeList(l1);
    freeList(l2);

    l1 = fromArray(v, 6);
    l2 = fromArray(x, 3);
    l3 = listIntersec(l1, l2);
    assert(l3 == NULL);
    freeList(l3);
    freeList(l1);
    freeList(l2);

    printf ("OK!\n");
    return 0;
}