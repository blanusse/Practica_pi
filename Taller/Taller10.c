#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include "../Lib/list.h"

#define BLOCK   10


//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
//EJ 1
// int alfabeto(char *text) {
//     if(*(text+1) == 0)
//         return 1;
//     if(*text < *(text+2))
//         return alfabeto(text+2);
//     return 0;
// }


// int main() {
//     assert(alfabeto("a,b,c") == 1);
//     assert(alfabeto("a,g,c") == 0);
//     assert(alfabeto("a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z") == 1);
//     assert(alfabeto("a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,a") == 0);
//     assert(alfabeto("z") == 1);
//     assert(alfabeto("z,a") == 0);
//     assert(alfabeto("a,z") == 1);
//     assert(alfabeto("a,a,a,a,a") == 0);
//     assert(alfabeto("c,i,a") == 0);
//     assert(alfabeto("b,b,c") == 0);
//
//     puts("OK!");
//     return 0;
// }

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
//EJ2

//
//
//
// tList strToListUpper(char *text) {
//     if(text == NULL || *text == 0)
//         return NULL;
//
//     if(isupper(*text)) {
//         tList newList = malloc(sizeof(tNode));
//         newList->head = *text;
//         newList->tail = strToListUpper(text+1);
//         return newList;
//     }
//     return strToListUpper(text+1);
// }
//
//
// char *listToString(tList l)
// {
//     tList aux = l;
//     char *s = NULL;
//     int i = 0;
//     while (aux != NULL)
//     {
//         if (i % BLOCK == 0)
//             s = realloc(s, i + BLOCK);
//         s[i] = aux->head;
//         aux = aux->tail;
//         i++;
//     }
//     s = realloc(s, i + 1);
//     s[i] = 0;
//     return s;
// }
//
void freeList(tList l)
{
    if (l != NULL)
    {
        freeList(l->tail);
        free(l);
    }
}
//
// int main()
// {
//     tList aux = strToListUpper("AbCdEfG");
//     char *strList = listToString(aux);
//     assert(!strcmp(strList, "ACEG"));
//     freeList(aux);
//     free(strList);
//
//     aux = strToListUpper("");
//     strList = listToString(aux);
//     assert(!strcmp(strList, ""));
//     freeList(aux);
//     free(strList);
//
//     aux = strToListUpper("Hoy vinimos a ver a Roman al Bombonera");
//     strList = listToString(aux);
//     assert(!strcmp(strList, "HMM"));
//     freeList(aux);
//     free(strList);
//
//     aux = strToListUpper("no va a quedar ninguna porque son todas minusculas");
//     strList = listToString(aux);
//     assert(!strcmp(strList, ""));
//     freeList(aux);
//     free(strList);
//
//     aux = strToListUpper(NULL);
//     strList = listToString(aux);
//     assert(!strcmp(strList, ""));
//     freeList(aux);
//     free(strList);
//
//     aux = strToListUpper("solo van a quedar las siguientes letras ABCDEFGHIJKLMNOPQRSTUVWXYZ");
//     strList = listToString(aux);
//     assert(!strcmp(strList, "ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
//     freeList(aux);
//     free(strList);
//
//     puts("OK!");
// }


//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
//EJ3

//
// tList concatenarLista(tList l1, tList l2) {
//     if(l2 == NULL)
//         return NULL;
//     if(l1==NULL) {
//         tList aux = malloc(sizeof(tNode));
//         aux->head = l2->head;
//         aux->tail = concatenarLista(l1, l2->tail);
//         return aux;
//     }
//     l1->tail = concatenarLista(l1->tail, l2);
//     return l1;
// }
//
//
//
int checkElems(const tList list, const int v[], int dim) {
    int i;
    tList aux;
    for(i=0, aux=list; i<dim && aux != NULL; i++, aux = aux->tail) {
        if ( aux->head != v[i])
            return 0;
    }
    return aux == NULL && i==dim;
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

// int
// main(void) {
//     int v1[] = {4,3,7};
//     tList l1 = fromArray(v1, 3);
//     int v2[] = {3,2,6};
//     tList l2 = fromArray(v2, 3);
//     int v1yv2[] = {4,3,7,3,2,6};
//     tList l1yl2 = concatenarLista(l1, l2);
//     assert(checkElems(l1yl2, v1yv2, 6));
//     freeList(l1yl2);
//     freeList(l2);
//
//     tList l3 = NULL;
//     tList l4 = fromArray(v1yv2, 6);
//     tList l3yl4 = concatenarLista(l3, l4);
//     assert(checkElems(l3yl4, v1yv2, 6));
//     freeList(l3yl4);
//     freeList(l4);
//
//     printf("OK!\n");
//     return 0;
// }

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
//EJ4


tList deleteAll(tList l1, tList l2) {
    if(l2 == NULL || l1 == NULL)
        return l1;

    if(l1->head < l2->head) {
        l1->tail = deleteAll(l1->tail, l2);
        return l1;
    }
    if(l1->head > l2->head) {
        return deleteAll(l1, l2->tail);
    }
    tList aux = l1->tail;
    free(l1);
    return deleteAll(aux, l2->tail);
}



int main()
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








