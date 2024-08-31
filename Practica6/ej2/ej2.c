#include <stdio.h>
#include "../../Lib/getnum.h"
int divisorComunMaximo(int a, int b) {
    int divisor = 1;
    for(int i=1; i <= (a<b? a : b); i++) {
        if ((a % i == 0) && (b%i == 0) )
            divisor=i;
    }
    return divisor;
}
void simplificar(int a, int b) {
    if (b==0)
        a=0, b=0;
    int mcd = divisorComunMaximo(a, b);
    num /=mcd;
    den /=mcd;
}

int menuOpciones (void) {
    int opcion;
    do
        opcion = getint("1)Simplificar una funcion\n"
                        "2)Sumar dos fracciones\n3)Terminar la ejecucion\nElija una opcion: ");
    while (opcion!= 1 && opcion != 2 && opcion != 3);
    return opcion;
}

void sumaFracciones (int a, int b, int c, int d) {
    den = b*d;
    num = (a*d+b*c);
    simplificar(num, den);
}



int main() {
    int opcion = menuOpciones();
    int a, b, c, d;
    switch (opcion) {
        case 1:
            int num = getint("Ingrese el numerador: ");
            int den = getint("Ingrese el denominador: ");
            int mcd = divisorComunMaximo(num, den);
            printf("%d/%d", num/mcd, den/mcd);
        break;
        case 2:
            a = getint("Ingrese un numerador: ");
            b =getint("Ingrese un denominador: ");
            c = getint("Ingrese otro numerador: ");
            d =getint("Ingrese un denominador: ");
            sumaFracciones(a,b,c,d);
            printf("%d/%d", num, den);
        break;
        default:
            return 0;
    }
}