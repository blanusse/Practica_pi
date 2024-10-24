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
#define LENGTH  4
#define TAM     10

//Lee un renglon de entrada estandar hasta un tamaño maximo
int getLine(char aux[], int maxLength) {
    int c, i=0;
    printf("Ingrese un palo: ");
    for(i=0; (c = getchar()) != '\n'; i++ ) {
        if(i<maxLength)
            aux[i] = c;
    }
    aux[i++] = 0;
    return i;
}

//Lee un renglon de entrada estandar sin limite

char*  getLineNoLimit() {
    int c, i;
    char *aux = NULL;
    for(i=0; (c=getchar()) != '\n';) {
        if(i % TAM == 0) {
            aux = realloc(aux, i+TAM);
        }
        aux[i] = c;
    }
    aux = realloc(aux, i+1);
    aux[i] = 0;
    return aux;
}


int main() {
    int cantPalos = 0;
    do {
        cantPalos = getint("Ingrese la cantidad de palos: ");
    }while (cantPalos <= 0);

    char ** palos = malloc(cantPalos * sizeof(*palos));

    //OPCION 1
    // char aux[LENGTH+1];
    // for(int i=0; i<cantPalos; i++) {
    //     int leng = getLine(aux, LENGTH);
    //     palos[i] = malloc(leng * sizeof(char));
    //     strcpy(palos[i], aux);
    // }


    //OPCION 2

    for(int i=0; i<cantPalos; i++) {
        palos[i] = getLineNoLimit();
    }


    //Agrego un palo
    palos = realloc(palos, (cantPalos + 1)*sizeof(char*));
    char *s = "Un palo mas";
    palos[cantPalos++] = strcpy(malloc(strlen(s) + 1), s);

    // palos[1] = malloc(6);
    // strcpy(palos[1], "Basto");
    //
    // palos[2] = malloc(4);
    // strcpy(palos[2], "Oro");
    //
    // palos[3] = malloc(7);
    // strcpy(palos[3], "Espada");
    //
    //
    // //Paso a mayuscula todas las letras de la primer palabra
    // for(int i=0; palos[0][i] != '\0'; i++) {
    //     palos[0][i] = toupper(palos[0][i]);
    // }
    //
    // //Quiero que en vez de "Espada" diga "Espadita"
    // palos[3] = realloc(palos[3], 9);
    // strcpy(palos[3], "Espadita");

    //Imprimir los palos

    for(int i=0; i<cantPalos; i++) {
        printf("%s\n", palos[i]);
    }


    //Liberar memoria reservada
    for(int i=0; i< cantPalos; i++) {
        free(palos[i]);
    }
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------





