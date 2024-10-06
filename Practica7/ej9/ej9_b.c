#include <inttypes.h>
#include <stdio.h>
#include "../../Lib/getnum.h"
#include "../../Lib/random.h"
#define MAX 90
#define COLUMNAS 5
#define FILAS 3
typedef  int TipoLinea[5];
typedef  TipoLinea  TipoCarton [3];
#define N   15



int buscarBolilla(TipoCarton carton, int bolilla) {
    int found = 0;
    for(int i=0;!found &&  i<FILAS; i++) {
        for(int k=0;!found && k<COLUMNAS; k++) {
            if(carton[i][k] == bolilla) {
                found =1;
                carton[i][k] = 0;
            }


        }
    }
    return found;
}

int controlarLineas(TipoLinea linea) {
    int checkCount = 0;

    for(int i=0; i<COLUMNAS; i++) {
        if(linea[i] == 0)
            checkCount++;
    }

    return checkCount/COLUMNAS;
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

int sacarBolilla(int bolillero[], int cantBolillero) {
    int bolillaActual = randInt(1, cantBolillero);
    bolillero[bolillaActual-1] = bolillero[cantBolillero-1];
    bolillero[cantBolillero-1] = 0;


    --cantBolillero;
    return bolillaActual;
}

int controlarCarton(TipoCarton carton, int bolilla) {
    int cantFil=0;
    if(buscarBolilla(carton, bolilla)) {
        for(int i=0; i<FILAS; i++) {
            if(controlarLineas(carton[i]))
                cantFil++;
        }
    }
    return cantFil;
}

void imprimirCarton(TipoCarton carton) {
    for(int i=0; i<FILAS; i++) {
        for(int k=0; k<COLUMNAS; k++) {
            printf("%d\t", carton[i][k]);
        }
        printf("\n");
    }
    printf("\n\n");

}

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

void generarCarton(TipoCarton carton) {

    int aux[MAX];
    int limitAux = MAX-1;
    for(int i=0; i<MAX; i++) {
        aux[i] = i+1;
    }

    for(int i=0; i<FILAS; i++) {

        for(int k=0; k<COLUMNAS; k++) {
            int aleatorio = randInt(1, MAX-1);
            carton[i][k] = aux[aleatorio];
            aux[aleatorio] = aux[limitAux--];
        }
    }
}

int jugar(int bolillero[], TipoCarton carton1, TipoCarton carton2) {
    int ganador=0, bolillaActual, bolillasOut = MAX;
    int i=0;
    //Pongo el iterador pq sino puede ser larguisimo el juego
    while(!ganador && i<10) {
        bolillaActual = sacarBolilla(bolillero, bolillasOut);
        printf("Se saca la bolilla nro %d y es el numero: %d\n", MAX-bolillasOut+1, bolillaActual);

        int filas1 = controlarCarton(carton1, bolillaActual);
        int filas2 = controlarCarton(carton2, bolillaActual);

        for(int k=0; k<N; k++) {
            printf("Carton del jugador 1:\n");
            imprimirCarton(carton1);
        }

        i++;

        if(filas1 == FILAS)
            ganador = 1;
        else if(filas2 == FILAS)
            ganador = 2;
    }
    return ganador;

}

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------





int main() {
    randomize();
    TipoCarton *carton = malloc(N*sizeof(TipoCarton));
    generarCarton(carton1);
    generarCarton(carton2);

    int bolillero[MAX];
    for(int i=0; i<MAX; i++) {
        bolillero[i] = i+1;
    }

    int ganador = jugar(bolillero, carton1, carton2);

    printf("El ganador es el jugador numero %d!!", ganador);





}