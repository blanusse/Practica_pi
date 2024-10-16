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

int chequarJugada(tCarta *mano) {
    int jugada=0;
    int aux[RANGO] = {0};
    for(int i=0; i<MANO; i++) {
        aux[mano[i].valor - 1]++;
    }
    for(int i=0; i<RANGO; i++) {
        if(aux[i] == POKER)
            jugada = POKER;
        else if(aux[i] == PIERNA)
            jugada = PIERNA;
        else if(aux[i] == PAR)
            jugada = PAR;
    }
    return jugada;
}





int main() {
    randomize();
    tCarta mazoOriginal[TOTAL];
    generarMazo(mazoOriginal);
    tCarta mano[MANO];
    agarrarCartas(mazoOriginal, mano);
    for(int i=0; i<MANO; i++) {
        printf("%d de %s\n", mano[i].valor, mano[i].palo);
    }
    printf("Jugada: %d", chequarJugada(mano));

}
