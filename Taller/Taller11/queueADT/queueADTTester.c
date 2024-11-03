#include <stdio.h>
#include <assert.h>
#include "queueADT.h"

int
main(void) {
    queueADT q = newQueue();
    queue(q, 5);
    queue(q, 9);
    queue(q, 3);
    int aux;
    dequeue(q, &aux);
    assert(aux == 5);
    dequeue(q, &aux);
    assert(aux == 9);
    queue(q, 1);
    dequeue(q, &aux);
    assert(aux == 3);
    dequeue(q, &aux);
    assert(aux == 1);
    assert(isEmpty(q) == 1);
    freeQueue(q);
    queueADT t = newQueue();
    queue(t, 5);
    queue(t, 9);
    queue(t, 3);
    toBegin(t);
    while (hasNext(t)) { // 5 9 3
        printf("%d ", next(t));

    }
    freeQueue(t);
    printf("OK!\n");
    return 0;

}
