#include <stdio.h>
#include <string.h>

#include "../../lib/getnum.h"
#include "../../Lib/random.h"
#include <ctype.h>
#include <math.h>
#define X   5
#define RANGO   10



//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

int cantidadRegular(int incognita[], int numero[]) {
    int count = 0;
    int apariciones[RANGO] = {0};
    for(int i=0; i<X; i++) {
        apariciones[incognita[i]] = 1;
    }
    for(int i=0; i<X; i++) {
        if(apariciones[numero[i]] && incognita[i] != numero[i])
            count++;
    }
    return count;
}

int cantidadBien(int incognita[], int numero[]) {
    int count=0;
    for(int i =0; i<X; i++) {
        if(incognita[i] == numero[i])
            count++;
    }
    return count;
}

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------


void generarAleatorio(int icognita[]){

    int aux[] = {1,2,3,4,5,6,7,8,9};
    int swap, aleatorio;
    for (int i=0; i<X; i++){
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

int coincideNumero(int incognita[], int numero[]) {
    int iguales = 0;
    int cantB = cantidadBien(incognita, numero);
    int cantR = cantidadRegular(incognita, numero);

    if(cantB == X)
        iguales = 1;
    else {
        printf("%d bien y %d regular\n", cantB, cantR);
    }
    return iguales;
}

void
leerNumero( int numero[] ){

    int i, j, num, numOK;
    do{
        num= getint("Ingrese un numero de %d dígitos del 1 al 9 sin repetir:",X);
        for (i=X-1, numOK = 1; i>=0 && numOK ; i--, num/=10)
        {
            numero[i] = num % 10;
            if (numero[i] == 0)
                numOK = 0;
            else
                for (j=X-1; j>i && numOK ; j--)
                    if (numero[i] == numero[j])
                        numOK = 0;
        }
    }
    while (!numOK || num!=0);
}




//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

int main() {
    int level = elegirNivel();
    int numReal[X];
    int ganador = 0;
    generarAleatorio(numReal);
    int userNum[X];
    for(int i=0;!ganador && i<level; i++) {
        leerNumero(userNum);
        ganador = coincideNumero(numReal, userNum);
    }
    if(ganador)
        printf("Ganaste!");
    else printf("Perdiste!\n");
    printf("El numero era: ");
    for(int i=0; i<X; i++) {
        printf("%d", numReal[i]);
    }
}


