#ifndef __utillist__h
#define __utillist__h

typedef struct node * tList; 

typedef struct node {
		int elem;
		struct node * tail;
} tNode;


/*
** Funcion auxiliar para crear listas y poder testear las funciones
** Dado un vector, retorna una lista con sus elementos, en el mismo orden
*/
tList fromArray(const int v[], unsigned int dim );

/*
** Funcion auxiliar para verificar los elementos de una lista
** Retorna 1 si la lista y el vector contienen los mismos elementos en el mismo orden
*/
int checkElems(const tList list, const int v[], int dim);

/*
** Libera todos los nodos de la lista
*/
void freeList(tList list);
#endif