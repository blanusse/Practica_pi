#include <stdio.h>
#include "../../Lib/list.h"

// void map(tList l, int (*pFunc)(int)) {
//     if(l==NULL)
//         return;
//     l->head = pFunc(l->head);
//     map(l->tail, pFunc);
// }
//
//
int doble(int n) {
    return 2*n;
}

int doble(int n) {
    return 2*n;
}

   int main(void) {
       tList myList = newList();  // Depende de la implementación
       // habrá que pasarle la función
       add(myList, 3);
       add(myList, 4);
       add(myList, 2);
       map(myList, doble);
       

       return 0;
   }

