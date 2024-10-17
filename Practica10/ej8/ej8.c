#include <stdio.h>
#include <assert.h>
#include "../../lib/list.h"

//OPCION MAS LARGA
// tList listUnion(const tList l1, const tList l2) {
//     if(l1 == NULL && l2 == NULL)
//         return NULL;
//     if(l1==NULL) {
//         tList newList = malloc(sizeof(tNode));
//         newList->head = l2->head;
//         newList->tail = listUnion(l1, l2->tail);
//         return newList;
//     }
//     if(l2 == NULL) {
//         tList newList = malloc(sizeof(tNode));
//         newList->head = l1->head;
//         newList->tail = listUnion(l1->tail, l2);
//         return newList;
//     }
//     if(l1->head > l2->head) {
//         tList newList = malloc(sizeof(tNode));
//         newList->head = l2->head;
//         newList->tail = listUnion(l1, l2->tail);
//         return newList;
//     }
//     if(l1->head < l2->head) {
//         tList newList = malloc(sizeof(tNode));
//         newList->head = l1->head;
//         newList->tail = listUnion(l1->tail, l2);
//         return newList;
//     }
//     tList newList = malloc(sizeof(tNode));
//     newList->head = l1->head;
//     newList->tail = listUnion(l1->tail, l2->tail);
//     return newList;
// }

//Lo de antes, pero mas corto
tList listUnion(const tList l1, const tList l2) {
    if(l1 == NULL && l2 == NULL)
        return NULL;
    if(l2 != NULL && (l1==NULL || l1->head > l2->head)) {
        tList newList = malloc(sizeof(tNode));
        newList->head = l2->head;
        newList->tail = listUnion(l1, l2->tail);
        return newList;
    }
    if(l2==NULL || l1->head < l2->head){
        tList newList = malloc(sizeof(tNode));
        newList->head = l1->head;
        newList->tail = listUnion(l1->tail, l2);
        return newList;
    }
    tList newList = malloc(sizeof(tNode));
    newList->head = l1->head;
    newList->tail = listUnion(l1->tail, l2->tail);
    return newList;
}

int main(void) {

    int v[] = {1, 4, 5, 6, 7, 8};
    int w[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x[] = {2, 3, 9};

    tList l1 = fromArray(v, 6);
    tList l2 = fromArray(w, 9);
    tList l3 = listUnion(l1, l2);
    assert(checkElems(l3, w, 9));
    freeList(l3);

    l3 = listUnion(l2, l1);
    assert(checkElems(l3, w, 9));
    freeList(l3);

    l3 = listUnion(l2, l2);
    assert(checkElems(l3, w, 9));
    freeList(l3);

    l3 = listUnion(l2, NULL);
    assert(checkElems(l3, w, 9));
    freeList(l3);

    l3 = listUnion(NULL, l2);
    assert(checkElems(l3, w, 9));
    freeList(l3);
    freeList(l1);
    freeList(l2);
  
    l1 = fromArray(v, 6);
    l2 = fromArray(x, 3);
    l3 = listUnion(l1, l2);
    freeList(l1);
    freeList(l2);
    assert(checkElems(l3, w, 9));
    freeList(l3);


    printf ("OK!\n");
    return 0;
}