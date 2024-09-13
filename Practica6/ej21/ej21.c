#include <stdio.h>
#include "../../Lib/getnum.h"
#include "../../Practica5/ej8/ej8.h"


//Funcion que calcula el mcd y lo devuelve en su nombre (BackEnd)
int MaxComDiv(int a, int b) {
    int divisor = 1;
    for(int i=1; i <= (a<b? a : b); i++) {
        if ((a % i == 0) && (b%i == 0) )
            divisor=i;
    }
    return divisor;
}
//Funcion que simplifica la fraccion y lo cambia con los punteros (BackEnd)

void simplify (int *a, int *b) {
    int mcd = MaxComDiv(*a, *b);
    *a = *a/mcd;
    *b = *b/mcd;
}
//Funcion que suma y simplifica dos fracciones y lo cambia con los punteros (BackEnd)

void add (int *a1, int *a2, int *b1, int *b2) {

    *a1 = *a1 * *b2 + *b1 * *a2;
    *a2 *= *b2;
    simplify(a1, a2);
}

//Funcion que despliega un menu de opciones y devuelve la opcion  elegida en su nombre (FrontEnd)
int optionMenu () {
    int opcion=0;
    while (opcion > 3 || opcion < 1) {
        opcion = getint("1)Simplificar una funcion\n"
                            "2)Sumar dos fracciones\n3)Terminar la ejecucion\nElija una opcion: ");
    }
    return opcion;
}

int main() {

    int option = optionMenu();
    switch (option) {
        case 1: {
            int a = getint("Ingrese el numerador: "), b = getint("Ingrese el denominador: ");
            simplify(&a, &b);
            printf("%d/%d\n", a, b);
            break;
        }
        case 2: {
            int a = getint("Ingrese el numerador 1: "), b = getint("Ingrese el denominador 1: ");
            int c = getint("Ingrese el numerador 2: "), d = getint("Ingrese el denominador2: ");
            add(&a, &b, &c, &d);
            printf("%d/%d\n", a, b);
            break;
        }
        default: return 0;
    }
    return 0;
}