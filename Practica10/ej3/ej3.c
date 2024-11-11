#include <stdio.h>
#include "../../Lib/utillist.h"
#include <assert.h>
#include "../../Lib/listADT/listADT.h"

void order(tList l){
    if(l==NULL || l->tail == NULL)
        return;

    order(l->tail);
    int next = l->tail->head;
    if(l->head >= next) {
        l->tail = delete(l->tail, next);
    }
}



int main(void) {

    int v[] = {1,1,2,1,0,-1,3,3,3,3,3,10,9,100,100,998};
    int dimV = sizeof(v)/sizeof(v[0]);
    tList list = fromArray(v, dimV);

    order(list);
    int o[] = {1,2,3,10,100,998};
    assert(checkElems(list, o, sizeof(o)/sizeof(o[0]))==1);

    order(list);
    assert(checkElems(list, o, sizeof(o)/sizeof(o[0]))==1);
    freeList(list);

    tList empty = NULL;
    order(empty);
    assert(empty ==NULL);

    list = fromArray(v,1);
    order(list);
    assert(list->head ==1 && list->tail == NULL);
    freeList(list);

    int w[] = {1,1,1,1,1,1,1,1,1,1};
    list = fromArray(w, sizeof(w)/sizeof(w[0]));
    order(list);
    assert(list->head ==1 && list->tail == NULL);
    freeList(list);

    printf ("OK!\n");
    return 0;
}

