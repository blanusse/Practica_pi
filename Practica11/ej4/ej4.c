#include <stdio.h>

#define N   3

int main() {
    //p1 es un arreglo de punteros a funciones que no reciben parámetros y devuelven punteros a double.
    double *(*p[])(void) = {};

    //p2 es una función que recibe un puntero a char y devuelve un puntero a un arreglo de 3x5 enteros.
    int **p2(char *l);

    //p3 es un puntero a un arreglo de N punteros a función que reciben un entero y retornan un puntero a entero.
    int *(*(*p3)[N]) (int a);

}
