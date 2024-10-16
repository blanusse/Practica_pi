#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include "../../Lib/random.h"


#define MANO   5
#define TOTAL   52
#define PALOS   4
#define RANGO   13

#define PAR     2
#define PIERNA  3
#define POKER   4

typedef struct {
    int valor;
    char *palo;
}tCarta;

// typedef tCarta tMazo[TOTAL];
// typedef tCarta tMano[MANO];

void generarMazo(tCarta *mazo) {
    char *palos[] = {"Corazon", "Diamante", "Picas", "Trebol"};
    int cantCartas=0;
    for(int i=1; i<RANGO+1; i++) {
        for(int k=0; k<PALOS; k++) {
            mazo[cantCartas].valor = i;
            mazo[cantCartas].palo = palos[k];
            cantCartas++;
        }
    }
}

void agarrarCartas(tCarta *mazo, tCarta *mano) {
    for(int i=0; i<MANO; i++) {
        int cartaRandom = randInt(0, TOTAL-i-1);
        mano[i] = mazo[cartaRandom];
        tCarta aux = mazo[cartaRandom];
        mazo[cartaRandom] = mazo[TOTAL-1-i];
        mazo[TOTAL-1-i] = aux;
    }
}

int chequarJugada(tCarta *mano, int *cartaJuntada) {
    int jugada=0;
    int aux[RANGO] = {0};
    for(int i=0; i<MANO; i++) {
        aux[mano[i].valor - 1]++;
    }
    for(int i=0; i<RANGO; i++) {
        if(aux[i] == POKER) {
            jugada = POKER;
            *cartaJuntada = i+1;
        }
        else if(aux[i] == PIERNA) {
            jugada = PIERNA;
            *cartaJuntada = i+1;
        }
        else if(aux[i] == PAR) {
            jugada = PAR;
            *cartaJuntada = i+1;
        }
    }
    return jugada;
}

void jugar(tCarta *mano1, tCarta *mano2, int *puntaje1, int *puntaje2) {
    int carta1, carta2;
    int jugador1 = chequarJugada(mano1, &carta1);
    int jugador2 = chequarJugada(mano2 ,&carta2);

    if(jugador1 > jugador2) {
        (*puntaje1)++;
    }
    else if(jugador1 < jugador2) {
        (*puntaje2)++;
    }
    else {
        if(carta1 > carta2)
            (*puntaje1)++;
        else if(carta1 < carta2)
            (*puntaje2)++;
        else {
            (*puntaje1)++;
            (*puntaje2)++;
        }
    }
}



int main() {
    randomize();
    tCarta mazoOriginal[TOTAL];
    generarMazo(mazoOriginal);
    int puntaje1=0, puntaje2=0;
    tCarta jugador1[MANO];
    tCarta jugador2[MANO];
    printf("Jugador 1 \t\t Jugador 2\n");
    for(int i=0; i<TOTAL;i+=10) {
        agarrarCartas(mazoOriginal, jugador1);
        agarrarCartas(mazoOriginal, jugador2);
        jugar(jugador1, jugador2, &puntaje1, &puntaje2);
        printf("\t%d\t\t\t\t%d\n", puntaje1, puntaje2);
    }
    printf("\n");
    if(puntaje1 == puntaje2) {
        printf("Empate");
    }
    else if(puntaje1 > puntaje2) {
        printf("El jugador 1 gano");
    }
    else if(puntaje1 < puntaje2) {
        printf("El jugador 2 gano");
    }


}
