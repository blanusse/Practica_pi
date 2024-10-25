#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



void transforma(int v[], size_t dim, int (*pFunc)(int)) {
    if(dim == 0)
        return;
    v[dim-1] = pFunc(v[dim-1]);
    transforma(v, dim-1, pFunc);
}


int cuadrado(int x) {
    return x * x;
}

// Sólo para testing
static void
assertArrayEquals(const int * expected, const int * actual, size_t dim) {
    for(int i = 0; i < dim; i++) {
        assert(expected[i] == actual[i]);
    }
}

int
main(void) {
    int v1[] = {2,3,4,5};
    transforma(v1, 4, cuadrado);
    int v1Expected[] = {4,9,16,25};
    assertArrayEquals(v1Expected, v1, 4);

    printf("OK!\n");
    return 0;
}

