#include <stdio.h>
#include <stdlib.h>
#include "../../Lib/listADT/listADT.h"


int getElementAtIndexP11(const tList l, unsigned int index) {
    if(l==NULL){
        fprintf(stderr, "La lista tiene menos elementos que %d.", index);
        exit(1);
    }
    if(index == 0)
        return l->head;
    return getElementAtIndex(l->tail, --index);
}