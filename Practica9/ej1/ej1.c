#include <stdio.h>

int sumatoria(int v[], unsigned int dim) {
    if(dim==0)
        return 0;
    return *v + sumatoria(++v, dim-1);
}

int main() {
    int vec[] = {1, 2, 3, 4, 5};
    printf("%d", sumatoria(vec, 5));
}