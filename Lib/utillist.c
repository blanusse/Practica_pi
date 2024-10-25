#include <stdio.h>
#include <stdlib.h>
#include "utillist.h"

/*
** Funcion auxiliar para crear listas y poder testear las funciones
** Dado un vector, retorna una lista con sus elementos, en el mismo orden
*/
tList fromArray(const int v[], unsigned int dim ) {
  tList ans = NULL;
  while (dim) {
     tList aux = malloc(sizeof(tNode));
     aux->head = v[--dim];
     aux->tail = ans;
     ans = aux;
  }
  return ans;
}

/*
** Funcion auxiliar para verificar los elementos de una lista
** Retorna 1 si la lista y el vector contienen los mismos elementos en el mismo orden
*/
int checkElems(const tList list, const int v[], int dim) {
  int i;
  tList aux;
  for(i=0, aux=list; i<dim && aux != NULL; i++, aux = aux->tail) {
    if ( aux->head != v[i])
       return 0;
  }
  return aux == NULL && i==dim;
}

void freeList(tList list) {
    if ( list == NULL)
       return;
    freeList(list->tail);
    free(list);
}