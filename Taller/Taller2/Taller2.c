#include <stdio.h>
#include <math.h>
#include "../Lib/getnum.h"

/*
int main() {
    printf("Ecuacion cuadratica: Ax^2 + Bx + C\n");
    float raiz1 = 0, raiz2 = 0;
    float a = getint("Ingrese el coeficiente A: ");
    float b = getint("Ingrese el coeficiente B: ");
    float c = getint("Ingrese el coeficiente C: ");
    if (a==0)
        printf("Ingresar una ecuacion cuadratica");
    else if ((b*b-4*a*c)<0)
        printf("Cuadratica con raices complejas");
    else {
        raiz1 = (-b+sqrt(b*b-4*a*c))/(2*a);
        raiz2 = (-b-sqrt(b*b-4*a*c))/(2*a);
        printf("raiz 1= %.3f; raiz 2= %.3f", raiz1, raiz2);
    }
    return 0;
}
*/

/*
int main() {
    int suma = 0, digito;
    for(int c=getchar(); c != '\n'; c=getchar()) {
        digito = c - '0';
        suma += digito;
    }
    printf("La suma es: %d", suma);
    return 0;
}
*/
/*
int main() {
    float num = getfloat("Ingrese un numero decimal: ");
    int numEntero = num, sumatoria=0;
    float numDecimal= num-numEntero;
    for (; numDecimal<100000000000000 ; numDecimal *= 10) {
        sumatoria += (int)(numDecimal*10) % 10;
    }
    printf("La suma es: %d", sumatoria);
    return 0;
}
*/

int main() {
    int decimal=0, sumatoria=0;
    for(int c=getchar(); (c != '\n') && ((c>= '0' && c<= '9') || c == '.'); c=getchar()) {
        if (decimal == 1)
            sumatoria += c - '0';
        if (c == '.')
            decimal=1;
    }
    printf("La suma de la parte decimal es: %d", sumatoria);
    return 0;
}





