#include <stdio.h>

#include "../../Lib/random.h"
#define CANT_NAIP   5
#define RANGO   12
#define PAR     2
#define PIERNA  3
#define POKER   4


struct tCarta {
    int num;
    char *palo;
};

typedef struct tCarta tMano[CANT_NAIP];


int cualJuego(tMano seleccion) {
    int aux[RANGO] = {0};
    for(int i=0; i<CANT_NAIP; i++) {
        aux[seleccion[i].num - 1]++;
    }
    for(int i=0; i<RANGO; i++) {
        if(aux[i] == 2)
            return PAR;
        if(aux[i] == 3)
            return PIERNA;
        if(aux[i] == 4)
            return POKER;
    }
    return 0;
}

int jugada() {
    tMano seleccion;
    char *palos[] = {"Basto", "Oro", "Espada", "Copa"};
    for(int i=0; i<CANT_NAIP; i++) {
        seleccion[i].num = randInt(1, RANGO);
        seleccion[i].palo = palos[randInt(0, 3)];
        printf("%d de %s\n", seleccion[i].num, seleccion[i].palo);
    }

    return cualJuego(seleccion);
}

int main() {
    randomize();
    printf("%d\n", jugada());

}

