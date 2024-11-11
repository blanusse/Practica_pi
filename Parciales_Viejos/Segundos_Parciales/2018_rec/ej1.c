#include <stdio.h>
#include <stdlib.h>

typedef struct node * tList;

typedef struct node {
    int elem;
    struct node * tail;
} TNode;

tList fromArray(const int v[], unsigned int dim ) {
    tList ans = NULL;
    while (dim) {
        tList aux = malloc(sizeof(TNode));
        aux->elem = v[--dim];
        aux->tail = ans;
        ans = aux;
    }
    return ans;

}
int checkElems(const tList list, const int v[], int dim) {
    int i;
    tList aux;
    for(i=0, aux=list; i<dim && aux != NULL; i++, aux = aux->tail) {
        if ( aux->elem != v[i])
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

void listDelete(tList l) {
    if(l == NULL || l->tail == NULL) {
        return;
    }
    listDelete(l->tail);
    int next = l->tail->elem;
    if(l->elem >= next) {
        l->tail =
    }
}

int main() {
    int v[10] = {1, 2, 3, 5, 9, 1, 2, 8, 9, 10};
    tList n = fromArray(v, 10);
    int v2[] = {1, 2, 3, 5, 9, 10};
    n = listDelete(n);
    checkElems(n, v2, 6);

    printf("OK!");
    freeList(n);
}



