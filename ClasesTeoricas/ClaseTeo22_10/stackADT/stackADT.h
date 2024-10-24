#ifndef TEORICAS_C_STACK_H
#define TEORICAS_C_STACK_H

typedef struct stackCDT * stackADT;

//Crea un stack y devuelve la direccion
stackADT newStack(void);

//Libera el stack completo
// void freeStack(stackADT s);

//Se fija si el stack esta vacio
int isEmpty(const stackADT s);

//Devuelve el elemento que esta arriba de la pila, no la modifica
int peek(const stackADT s);

//Pone un elemento
void push(stackADT s, int elem);

//Saca un elemento y lo devuelve en el nombre
int pop(stackADT s);



//Se fija si el stack esta lleno, en caso de tener un limite
// int isFull(const stackADT s);


#endif
