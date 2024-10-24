#include <stdio.h>
#include <assert.h>


int isNull(const int v[],  unsigned int dim) {
    if(dim == 0)
        return 1;
    if(v[dim-1] != 0)
        return 0;
    return isNull(v, dim-1);
}


int main() {
    int v[] = {9, 3, 2, 3};
    assert(!isNull(v, 4) && !isNull(v, 1));
    assert(isNull(v, 0));
    int v2[100] = {0};
    assert(isNull(v2, 100));

    printf("OK!");
}