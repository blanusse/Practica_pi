#include <stdio.h>

#include "../Lib/getnum.h"

double potencia(double base, int exp) {
    double resultado=1;
    if (exp<0) {
        base = (1/base);
        exp = -exp;
    }
    else if (exp == 0)
        return 1;
    while (exp>0){
        resultado = base * resultado;
        --exp;
    }
    return resultado;
}

int main() {
    double base = getint("Ingrese una base: ");
    int exp = getint("Ingrese un exponente: ");
    printf("%.3f", potencia(base, exp));
    return 0;
}