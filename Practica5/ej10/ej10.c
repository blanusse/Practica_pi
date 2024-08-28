#include <stdio.h>

#include "../../Lib/getnum.h"


int menuOpciones (void) {
    int opcion = getint("1)Simplificar una funcion\n"
                        "2)Sumar dos fracciones\n3)Terminar la ejecucion\nElija una opcion: ");
    return opcion;
}

int divisorComunMaximo(int a, int b) {
    int divisor = 1;
    for(int i=1; i <= (a<b? a : b); i++) {
        if ((a % i == 0) && (b%i == 0) )
            divisor=i;
    }
    return divisor;
}

void simplificar(int a, int b) {
    printf("%d/%d", a/divisorComunMaximo(a, b), b/divisorComunMaximo(a, b));
}

void sumaFracciones (int a, int b, int c, int d) {
    int numerador, denominador = b*d;
    numerador = (denominador/b) * a + (denominador/d * c);
    simplificar(numerador, denominador);
}







int main() {
    int opcion = menuOpciones();
    switch (opcion) {
        case 1:
            simplificar(getint("Ingrese el numerador: "), getint("Ingrese el denominador: "));
        break;
        case 2:
            sumaFracciones(getint("Ingrese el numerador de la fraccion 1: "),
                getint("Ingrese el denominador de la fraccion 1: "),
                getint("Ingrese el numerador de la fraccion 2: "),
                getint("Ingrese el denominador de la fraccion 2: "));
        break;
        default:
            return 0;
    }

}
