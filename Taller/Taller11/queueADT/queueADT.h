
#ifndef QUEUEADT_H
#define QUEUEADT_H

typedef struct queueCDT *queueADT;
typedef int elementType;


queueADT newQueue(void);

// Agrega un elemento al final de la cola
void queue(queueADT q, elementType n);

// Remueve un elemento del principio de la cola y lo deja en out
void dequeue(queueADT q, elementType *out);

void freeQueue(queueADT q);

int isEmpty(queueADT q);



#endif //QUEUEADT_H
