#include "list.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


int isEmpty(tList l) {
    return l == NULL;
}


int size(tList l) {
    if(l == NULL)
        return 0;
    return 1 + size(l->tail);
}


int belongs(tList l, int elem) {
    if(l==NULL || l->head > elem) {
        return 0;
    }
    if(l->head == elem)
        return 1;
    return belongs(l->tail, elem);
}


tList add(tList l, int elem) {
    if(l==NULL || elem < l->head) {
        tList aux = malloc(sizeof(tNode));
        aux->head = elem;
        aux->tail = l;
        return aux;
    }
    if(elem == l->head) {
        return l;
    }
    l->tail = add(l->tail, elem);
    return l;
}


void freeList(tList l) {
    if(l == NULL)
        return;
    freeList(l->tail);
    free(l);
}

int head(tList l) {
    if(l==NULL) {
        fprintf(stderr, "La lista es vacia");
        exit(1);
    }
    return l->head;
}

tList tail(tList l) {
    if(l==NULL) {
        fprintf(stderr, "La lista es vacia");
        exit(1);
    }
    return l->tail;
}

tList delete(tList l, int elem){
    if(l==NULL || elem < l->head)
        return l;
    if(l->head == elem) {
        tList aux = l->tail;
        free(l);
        return aux;
    }
    l->tail = delete(l->tail, elem);
    return l;
}


int * toArray(const tList l, int *dim) {
    *dim = size(l);
    if(*dim == 0)
        return NULL;
    tList aux = l;
    int *v = malloc(*dim * sizeof(int));
    for(int i=0; i<*dim; i++) {
        v[i] = l->head;
        aux = aux->tail;
    }
    return v;
}

int getElementAtIndex(const tList l, unsigned int index) {
    if(l==NULL){
        fprintf(stderr, "La lista tiene menos elementos que %d.", index);
        exit(1);
    }
    if(index == 0)
        return l->head;
    return getElementAtIndex(l->tail, --index);
}



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


int checkElems(const tList list, const int v[], int dim) {
    int i;
    tList aux;
    for(i=0, aux=list; i<dim && aux != NULL; i++, aux = aux->tail) {
        if ( aux->head != v[i])
            return 0;
    }
    return aux == NULL && i==dim;
}


