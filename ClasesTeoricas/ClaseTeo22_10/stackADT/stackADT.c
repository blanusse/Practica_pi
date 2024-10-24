#include <stdlib.h>
#include "stackADT.h"
#include <assert.h>
#define BLOCK   10

typedef struct stackCDT{
    int *elems;
    int cantElems;
} stackCDT;


stackADT newStack(void) {
    return calloc(1, sizeof(stackCDT));
}


void freeStack(stackADT s) {
    free(s->elems);
    free(s);
}

int isEmpty(const stackADT s) {
    return s->elems == 0;
}

void push(stackADT s, int elem) {
    if(s->cantElems % BLOCK == 0) {
        s->elems = realloc(s->elems, (s->cantElems + BLOCK)* sizeof(int));
    }
    s->cantElems += 1;
    s->elems[s->cantElems] = elem;
}

int pop(stackADT s) {
    int aux = peek(s);
    --s->cantElems;
    return aux;


}

int peek(stackADT s) {
    assert(isEmpty(s) == 0);
    return s->elems[s->cantElems];
}

// int isFull(stackADT s) {
//
// }


