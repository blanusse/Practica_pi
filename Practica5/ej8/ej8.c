#include <stdio.h>
#include <math.h>
#include "ej8.h"

#include "../../Lib/getnum.h"

//PUNTO A
double redondeo(double num, int decimales) {
    int i=1;
    for (; i <= decimales; i++) {
        num *= 10;
    }
    num =num+0.5;
    return ((int)num)/(pow(10, i-1));
}


int equal(double a, double b) {
    return (fabs(a-b) < 0.0000001);
}
//Funcion creada para los asserts
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

//PUNTO B

int menuOpciones (void) {
    getint("1) Redondeo al entero mas cercano\n2) Redondeo al decimal mas cercano\n"
           "3) Redondeo a la centesima mas cerca\n4) Redondeo a la milesima mas cerca\nIngrese una opcion: ");
}