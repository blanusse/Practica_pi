#include <assert.h>
#include <stdio.h>
#include <tgmath.h>

#include "../../Lib/getnum.h"
#define INCREMENTO 0.001
#define EPSILON 0.0005

//Se considera raiz si cambia el signo o la imagen es cero con un error de epsilon

double imagen(double x) {
    return sin(x);
}

//Para cada funcion que pide el enunciado hay que cambiar el return de la funcion de arriba y el EPSILON

void raices (double a, double b) {
    int signo, signoAnt = imagen(a)>=0 ? 1 : -1;
    for(double i = a; i <= b; i+=INCREMENTO) {
        signo = imagen(a)>=0 ? 1 : -1;
        if (fabs(imagen(i)) < EPSILON || signo != signoAnt)
           printf("%.3f es una raiz\n", i);
        signoAnt = imagen(a)>=0 ? 1 : -1;
    }
}

int main() {
    raices(-3, 10);
    return 0;
}

