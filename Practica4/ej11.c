#include <stdio.h>

int  mayorTres(int a, int b, int c) {
    return ((a) > (b) ? ((a) > (c) ? (a) : (c)) : ((b>c)? (b) : (c)));
}
/*Codigo para evaluar la funcion*/

int main() {
    int x=11, y= 9, z=11;
    printf("el mas grande es: %d", mayorTres(++x, y, z));
    return 0;
}