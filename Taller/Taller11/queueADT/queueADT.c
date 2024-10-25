#include "queueADT.h"

#include <stdlib.h>

typedef struct node * tList;

typedef struct node {
    elementType value;
    struct node *next;
} tNode;

typedef struct queueCDT {
    tNode *first;
    tNode *last;
}queueCDT;

queueADT newQueue(void) {
    return calloc(1, sizeof(queueCDT));
}

// tenes que tener en cuenta distintos casos por ejemplo, cuando pasas de tener un nodo a tener 2. o cunado no tenias ninguno y tenes 1.
void queue(queueADT q, elementType n) {
    tList aux = malloc(sizeof(tNode));
    aux->next = NULL;
    aux->value = n;
    if (q->first == NULL) {
        q->first = aux;
    }
    else {
        q->last->next = aux;
    }
    q->last = aux;
}

void dequeue(queueADT q, elementType *out) {
    *out = q->first->value;
    tList aux = q->first->next;
    free(q->first);
    q->first = aux;

}

void freeQueue(queueADT q) {
    if(q->first == NULL) {
        free(q);
        return;
    }
    tList aux = q->first;
    q->first = q->first->next;
    free(aux);
}



int isEmpty(queueADT q) {
    return q->first == NULL;
}