#ifndef TEORICAS_C_LIST_H
#define  TEORICAS_C_LIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int head;
    struct node * tail;
} tNode;

typedef struct node * tList;


//Devuelve 1 si la lista es vacia, 0 si no lo es
int isEmpty(tList l);

//Cuenta los elementos de una lista
int size(tList l);

//Retorna 1 si elem esta en la lista
//Siempre y cuando la lista este ordenada de menor a mayor
int belongs(tList l, int elem);

//Agrega un elemento a la lista y retorna la direccion de memoria donde comienza la lista
tList add(tList l, int elem);

//Libera todos los recursos utilizados por la lista
void freeList(tList l);

//Devuelve el valor del head de una lista
int head(tList l);

//Devuelve el puntero de una lista
tList tail(tList l);

//Elimina algun componente de la lista qeu tenga en el head el elem
tList delete(tList l, int elem);

//Convierte una lista en un arreglo dinamico
int * toArray(const tList l, int *dim);

//Devuelve el head de el elemento ubicado en el indice dado
int getElementAtIndex(const tList l, unsigned int index);

/*
** Funcion auxiliar para crear listas y poder testear las funciones
** Dado un vector, retorna una lista con sus elementos, en el mismo orden
*/
tList fromArray(const int v[], unsigned int dim);

/*
** Funcion auxiliar para verificar los elementos de una lista
** Retorna 1 si la lista y el vector contienen los mismos elementos en el mismo orden
*/
int checkElems(const tList list, const int v[], int dim);

//Realiza cierta funcion propuesta como puntero a todos los elementos
void map(tList l, int (*pFunc)(int));


#endif
