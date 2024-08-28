#include <stdio.h>
#define EPSILON 0.00001
#include <assert.h>
#include <math.h>

#include "../../Lib/getnum.h"

double potencia(double base, int exp) {
    double resultado=1;
    if (base == 0 && exp == 0)
        return -1;
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




// ¿Qué caso faltaría agregar?

double potencia(double base, int exponente);

int main(void){

    assert(potencia(0,0)==-1);

    for(int i=-10, j=1; i<10; i++, (i%2==0? j++ : 0)){
        assert(fabs(potencia(i, j)-pow(i, j))<=EPSILON);
    }
    assert(fabs(potencia(-2, -4)-pow(-2, -4))<=EPSILON);

    puts("OK!");
    return 0;
}