#include "multiSetADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
    multiSetADT m = newMultiSet();
    add(m, 10);
    add(m, 10);
    add(m, 20);
    add(m, 10);
    add(m, 30);
    add(m, 40);
    add(m, 40);
    assert(size(m) == 4);
    assert(removeM(m, 10) == 2);
    assert(removeM(m, 50)== 0);
    assert(removeM(m, 40)== 1);
    assert(size(m) == 4);
    int dim = 0;
    elemType *v = minElements(m, &dim);
    for(int i=0; i<dim; i++) {
        printf("%d\n", v[i]);
    }
    free(v);
    freeMultiSet(m);
    printf("OK!");
}