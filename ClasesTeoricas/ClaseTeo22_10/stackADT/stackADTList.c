#include <assert.h>
#include <stdio.h>
#include "stackADT.h"
#include <stdlib.h>



typedef struct nose {
    int head;
    struct node *tail;
} tNode;

typedef tNode * tList;

typedef struct stackCDT {
    tList first;
    int cantElems;
} stackCDT;

stackADT newStack(void) {
    return calloc(1, sizeof(struct stackCDT));
}



void push(stackADT s, int elem) {
    if(!isEmpty(s)) {
        tList aux = malloc(sizeof(tNode));
        aux->head = elem;
        aux->tail = s->first;
        s->first = aux;
    }
}


int isEmpty(const stackADT s) {
    return s->cantElems == 0;
}

int peek(stackADT s) {
    assert(!isEmpty(s));
    return s->first->head;
}

int pop(stackADT s) {
    int toReturn = peek(s);
    tList aux = s->first->tail;
    free(s->first);
    s->first = aux;
    return toReturn;
}

static void freeList(tList l) {
    if(l == NULL)
        return;
    tList aux = l->tail;
    free(l);
    freeList(aux);
}

void freeStack(stackADT s) {
    freeList(s->first);
    free(s);
}

int sizeStack(const stackADT s) {
    return s->cantElems;
}
