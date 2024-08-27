#include <math.h>
#include <stdio.h>
#include <tgmath.h>
#include "ej7.h"
#include "../Lib/getnum.h"
#define ERROR 0.0001


float factorial (int a) {
    float total = 1;
    for (; a>0; a--) {
        total *= a;
    }
    return total;
}

int equals(double a, double b) {
    return (fabs(a-b) < ERROR);
}

double ex(int x) {
    double suma = 1;
    for (int terminos = getint("Ingrese una cantidad de terminos: "), i=1; terminos > 0; terminos--, i++) {
        suma += (double)(pow(x, i))/(factorial(i));
    }
    return suma;
}

//Para fijar la precision, incluiria que la resta entre la funcion creada y la que ya existe sea menor a 0.00000001 o un numero mas chico
//pero estarias usando la funcion ya creada:

/*
double ex(int x) {
    double suma = 1;
    for(double real = exp(x), i=1; !equals(suma,real); i++ ) {
        suma += (double)(pow(x, i))/(factorial(i));
    }
    return suma;
}
*/