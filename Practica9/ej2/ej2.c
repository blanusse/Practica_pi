#include <stdio.h>
#define BLOCK   10

int sumaDigitos(int n) {
    if(n == 0) {
        return 0;
    }
    return n%BLOCK + sumaDigitos(n/10);
}

int main() {
    printf("%d", sumaDigitos(12345));
}