#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT_PALOS  4
#include <ctype.h>
#include "../Lib/getnum.h"


//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------


// float * leerNum(int *n) {
//     do {
//         *n = getint("Ingrese una cantidad de numeros: ");
//     }while (*n <= 0);
//     float * v = malloc(*n * sizeof(float));
//
//     for(int i=0; i< *n; i++) {
//         float num = getfloat("Ingrese un numero real: ");
//         *(v+i) = num;
//     }
//     return v;
//
// }
//
//
// int main() {
//     int dim;
//     float *aux = leerNum(&dim);
//     for(int i=0; i<dim; i++) {
//         printf("%.2f\t", aux[i]);
//     }
//     free(aux);
//     return 0;
// }

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------


int main() {
    char * palos[CANT_PALOS];
    char * p1 = malloc(strlen("Copa") + 1);
    char * copaCte = "Copa";
    strcpy(p1, copaCte);
    palos[0] = p1;

    palos[1] = malloc(6);
    strcpy(palos[1], "Basto");

    palos[2] = malloc(4);
    strcpy(palos[2], "Oro");

    palos[3] = malloc(7);
    strcpy(palos[3], "Espada");


    //Paso a mayuscula todas las letras de la primer palabra
    for(int i=0; palos[0][i] != '\0'; i++) {
        palos[0][i] = toupper(palos[0][i]);
    }

    //Quiero que en vez de "Espada" diga "Espadita"
    palos[3] = realloc(palos[3], 9);
    strcpy(palos[3], "Espadita");

    //Imprimir los palos

    for(int i=0; i<CANT_PALOS; i++) {
        printf("%s\n", palos[i]);
    }

    //Liberar memoria reservada

    for(int i=0; i<CANT_PALOS; i++) {
        free(palos[i]);
    }
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------





