#include <stdio.h>
#include <stdlib.h>

#define BLOCK   10


int *pares(const int *conj, size_t dim, size_t *nuevaDim) {
    int *nuevoVec = NULL;
    *nuevaDim=0;
    for(int i=0; i<dim; i++) {
        if(conj[i]%2 == 0) {
            if(i%BLOCK == 0)
                nuevoVec = realloc(nuevoVec, i*sizeof(int));
            nuevoVec[(*nuevaDim)++] = *conj;
        }
    }
    nuevoVec = realloc(nuevoVec, *nuevaDim * sizeof(int));
    return nuevoVec;
}

int main() {
    int v1[] = {1, 2, 7, 6, 9, 2};
    size_t dim = sizeof(v1)/sizeof(v1[0]);
    size_t dimRes;
    int *res = pares(v1, dim, &dimRes);
    for(int i=0; i<dimRes; i++) {
        printf("%d ", res[i]);
    }
    free(res);

}