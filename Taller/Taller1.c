#include <stdio.h>

// int main(void) {
//     unsigned char var, var1, var2, var3, var4;
//     var= 0xD8;
//     var1= (var>>6)&0x03;
//     var2= (var>>4)&0x03;
//     var3= (var>>2)&0x03;
//     var4= var&0x03;
//     return var1;
// }




//
// Created by Catalina Vivern on 18/10/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../lib/utillist.h" //ERA #include "utillist.h"

tList deleteAll(tList l1, const tList l2);

int main(void)
{
    int v1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    tList l1 = fromArray(v1, 9);
    int v2[] = {2, 4, 6, 8};
    tList l2 = fromArray(v2, 4);
    int v1sinv2[] = {1, 3, 5, 7, 9};
    tList l1sinv2 = deleteAll(l1, l2);
    assert(checkElems(l1sinv2, v1sinv2, 5));
    freeList(l1sinv2);

    int v3[] = {1, 2, 3, 4, 5, 6, 7};
    tList l3 = fromArray(v3, 7);
    int v4[] = {0, 1, 3, 5, 10, 11, 14};
    tList l4 = fromArray(v4, 7);
    int v3sinv4[] = {2, 4, 6, 7};
    tList l3sinv4 = deleteAll(l3, l4);
    assert(checkElems(l3sinv4, v3sinv4, 4));
    freeList(l3sinv4);

    int v5[] = {1, 2, 3, 4, 5, 6, 7};
    tList l5 = fromArray(v5, 7);
    int v6[] = {1, 2, 3, 4, 5, 6, 7};
    tList l6 = fromArray(v6, 7);
    tList l5sinv6 = deleteAll(l5, l6);
    assert(l5sinv6 == NULL);

    tList l7 = NULL;
    tList l8 = fromArray(v1, 9);
    tList l7sinv8 = deleteAll(l7, l8);
    assert(l7sinv8 == NULL);

    tList l9 = fromArray(v1, 9);
    tList l10 = NULL;
    tList l9sinv10 = deleteAll(l9, l10);
    assert(checkElems(l9sinv10, v1, 9));
    freeList(l9sinv10);

    puts("OK!");
    return 0;
}

//RTA DE LA CATEDRA
tList deleteAll(tList l1, const tList l2) { //estan ordenadas crecientemente
    if (l2==NULL) {
        return l1;
    }
    if (l1!=NULL) {
        if ( l1->elem == l2->elem ) {
            tList aux = l1;
            l1 = deleteAll(l1->tail, l2->tail);
            free(aux);
        } else if ( l1->elem < l2->elem ) {
            l1->tail= deleteAll(l1->tail, l2);
        } else {
            l1 = deleteAll(l1, l2->tail);
        }
    }
    return l1;
}

//LO Q HICE YO: mal
//Primero guardar el sgte y desp ...
/*
tList deleteAll(tList l1, const tList l2) {
    if (l1==NULL || l2==NULL) { //Si termino de recorrer la lista //NOTA: No hay q poner solo l1==NULL, tamb hay q poner l2==NULL
        return l1;
    }
    if ( l1->head > l2->head ) {
        //Aca tengo q linkear
        return deleteAll(l1, l2->tail);
    }
    if (l1->head < l2->head) {
        return deleteAll(l1->tail, l2);//
    }
    //Si no entro en ninguno de los dos
    tList aux=l1->tail;
    free(l1);
    return aux;
}

 */
