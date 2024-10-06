#include <stdio.h>
#include <string.h>

#include "../../lib/getnum.h"
#include "../../Lib/random.h"
#include <ctype.h>
#include <math.h>
#define RANGO   10



//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------




int cantidadRegular(int incognita[], int numero[], int digitos) {
    int count = 0;
    int apariciones[RANGO] = {0};
    for(int i=0; i< digitos; i++) {
        apariciones[incognita[i]] = 1;
    }
    for(int i=0; i< digitos; i++) {
        if(apariciones[numero[i]] && incognita[i] != numero[i])
            count++;
    }
    return count;
}

int cantidadBien(int incognita[], int numero[], int digitos) {
    int count=0;
    for(int i =0; i<digitos; i++) {
        if(incognita[i] == numero[i])
            count++;
    }
    return count;
}

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------


void generarAleatorio(int icognita[], int digitos){

    int aux[] = {1,2,3,4,5,6,7,8,9};
    int swap, aleatorio;
    for (int i=0; i<digitos; i++){
        aleatorio = randInt(i+1,9);
        swap = aux[i];
        aux[i] = aux[aleatorio-1];
        aux[aleatorio-1] = swap;
        icognita[i] = aux[i];
    }
}


int elegirNivel() {
    int level=0;
    do {
        level = getint("Ingrese el nivel del 1 al 10: ");
    }
    while (level < 1 || level > 10);
    return level;
}

int coincideNumero(int incognita[], int numero[], int digitos) {
    int iguales = 0;
    int cantB = cantidadBien(incognita, numero, digitos);
    int cantR = cantidadRegular(incognita, numero, digitos);

    if(cantB == digitos)
        iguales = 1;
    else {
        printf("%d bien y %d regular\n", cantB, cantR);
    }
    return iguales;
}

void
leerNumero( int numero[], int digitos){

    int i, j, num, numOK;
    do{
        num= getint("Ingrese un numero de %d dígitos del 1 al 9 sin repetir:",digitos);
        for (i=digitos-1, numOK = 1; i>=0 && numOK ; i--, num/=10)
        {
            numero[i] = num % 10;
            if (numero[i] == 0)
                numOK = 0;
            else
                for (j=digitos-1; j>i && numOK ; j--)
                    if (numero[i] == numero[j])
                        numOK = 0;
        }
    }
    while (!numOK || num!=0);
}


int pedirDigitos() {
    int digitos=0;
    do {
        digitos = getint("Ingrese la cantidad de digitos: ");
    }
    while (digitos < 1 || digitos > 10);
    return digitos;
}

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

int main() {
    int digitos = pedirDigitos();
    int level = elegirNivel();
    int numReal[digitos];
    int ganador = 0;
    generarAleatorio(numReal, digitos);
    int userNum[digitos];
    for(int i=0;!ganador && i<level; i++) {
        leerNumero(userNum, digitos);
        ganador = coincideNumero(numReal, userNum, digitos);
    }
    if(ganador)
        printf("Ganaste!");
    else printf("Perdiste!\n");
    printf("El numero era: ");
    for(int i=0; i<digitos; i++) {
        printf("%d", numReal[i]);
    }
}


