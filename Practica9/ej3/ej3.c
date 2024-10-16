#include <stdio.h>

int productoEsc(int a[], int b[], unsigned int dim) {
    if(dim ==0)
        return 0;
    return (*a * *b) + productoEsc(++a, ++b, dim-1);
}

int main() {
    int a[] = {1, 2, 3};
    int b[] = {1, 2, 3};
    printf("%d", productoEsc(a, b, 3));
}