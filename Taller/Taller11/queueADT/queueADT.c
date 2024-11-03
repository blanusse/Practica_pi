#include "queueADT.h"

#include <stdlib.h>

typedef struct node * tList;

typedef struct node {
    elementType value;
    struct node *next;
} tNode;



typedef struct queueCDT {
    tList first;
    tList last;
    tList current;
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

void freeQueueRec(tList list) {
    if(list == NULL)
        return;
    tList aux = list->next;
    free(list);
    freeQueueRec(aux);
}

void freeQueue(queueADT q) {
    freeQueueRec(q->first);
    free(q);
}



int isEmpty(queueADT q) {
    return q->first == NULL;
}


void toBegin(queueADT q) {
    q->current = q->first;
}
int hasNext(queueADT q) {
    if(q->current->next == NULL)
        return 0;
    return 1;
}
elementType next(queueADT q) {
    if(hasNext(q)) {
        elementType toReturn = q->current->value;
        q->current = q->current->next;
        return toReturn;
    }
}
