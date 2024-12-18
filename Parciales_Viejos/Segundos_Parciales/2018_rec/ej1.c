#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
    char head;
    int hits;
    struct node * tail;
} node;
typedef node * TList;

// TList addElem(TList l, char elem){
//     if(l == NULL ){ /*recorrio toda la lista y no lo encontro*/
//         TList new = malloc(sizeof(node));
//         new->hits = 0;
//         new->head = elem;
//         new->tail = NULL;
//         return new;
//     }
//     if(l->head == elem){
//         l->hits++;
//         return l;
//     }
//     TList aux = addElem(l->tail, elem);
//     if(aux->hits > l->hits){
//         TList aux2 = aux->tail;
//         aux->tail = l;
//         l->tail = aux2;
//         return aux;
//     }
//     l->tail = aux;
//     return l;
// }

TList addElem( TList list, char elem ){
    if ( list == NULL ){
        TList newNode = malloc(sizeof(node));
        newNode->head = elem;
        newNode->hits = 0;
        newNode->tail = NULL;
        return newNode;
    }
    if ( list->head == elem ){
        list->hits++;
        return list;
    }
    list->tail = addElem(list->tail, elem);

    if ( list->tail != NULL && list->tail->hits > list->hits ){
        TList aux = list;
        TList aux2 = list->tail->tail;
        list = list->tail;
        aux->tail = aux2;
        list->tail = aux;
    }
    return list;

}


int main(void) {
    // TList l = NULL;
    // l = addElem(l,
    // 'X');
    // l = addElem(l,
    // 'X');
    // l = addElem(l,
    // 'Z');
    // // (X,1) -> (Z,0)
    // assert(l->head == 'X'); assert(l->tail->head == 'Z');
    // l = addElem(l,
    // 'A');
    // // (X,1) -> (Z,0) -> (A,0) o bien (X,1) -> (A,0) -> (Z,0)
    // assert(l->head == 'X');
    // assert((l->tail->head == 'Z' && l->tail->tail->head == 'A')
    // || (l->tail->head == 'A' && l->tail->tail->head == 'Z'));
    // l = addElem(l,
    // 'A');
    // l = addElem(l,
    // 'A');
    // assert(l->head == 'A');
    // assert(l->tail->head == 'X');
    // assert(l->tail->tail->head == 'Z');
    // assert(l->tail->tail->tail == NULL);
    // // Se liberan todos los nodos de la lista
    // // puts( "OK");


    printf("Cata te amo muchisimo, infinito punto azul y amarillo");



    return 0;
}