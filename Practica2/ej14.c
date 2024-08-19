#include <stdio.h>
#include "../Lib/getnum.h"

int main() {
    int num1 = getint("Ingresar un entero: ");
    int num2 = getint("Ingresar otro entero: ");
    float prom = (num1+num2)/2;
    int suma = num1+num2;
    printf("El promedio es %.1f \n", prom);
    printf("La suma es %d \n", suma);
    num1<num2 ? printf("El menor es %d \n", num1) : printf("El menor es %d \n", num2);
    num1>num2 ? printf("El mayor es %d \n", num1) : printf("El mayor es %d \n", num2);
    num1==num2 ? printf("Son iguales \n"): printf("No son  iguales \n");

}
