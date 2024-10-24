#include <stdio.h>
#include "../lib/getnum.h"


// Funcion para escribir un arr
int readArray (float v[], int dim) {
    int i=0;
    while(i<dim) {
        float c =getfloat("Ingrese un numero real positivo: ");
        if(c<0)
            return i;
        v[i] = c;
        i++;

    }
    return i;
}
void escribirArreglo (const float v[], int dim) {
    for(int i=0; i<dim; i++)
        printf("%.2f  ", v[i]);
}

/*
int main() {
float v[DIM];
int dim = readArray(v, DIM);
escribirArreglo(v, dim);
}
*/
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
//FUNCION Para ver si un arreglo es ascendente
int esAscendente (const int a[], int dim) {
    int ascendente =1;
    for(int i=0; i<dim-1 && ascendente; i++) {
        if (a[i] >= a[i+1]) {
            ascendente = 0;
        }
    }
    return ascendente;
}

int main() {
    int a[] = {-1, 3, 9, 5};
    int dim = sizeof(a)/sizeof(a[0]);
    printf("%d", esAscendente(a, dim));
}