#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "../../Lib/getnum.h"
#include "../../Lib/random.h"
#define CANT_PAL    20
#define LETRAS      6
#define VIDAS   7


void elegirPalabra(char almacenPalabras[][LETRAS+1], char actualWord[LETRAS]) {
    randomize();

    int aleat = randInt(0, CANT_PAL-1);
    strcpy(actualWord, almacenPalabras[aleat]);
}

int comparaLetra(char letra, char actualWord[], int apariciones[]) {
    int esta=0;
    for(int i=0; i<LETRAS; i++) {
        if(actualWord[i] == letra) {
            apariciones[i] = 1;
            esta = 1;
        }
    }
    return esta;
}


void actualizaPalabra(char userWord[],char actualWord[] ,int apariciones[], int *count) {
    for(int i=0; i<LETRAS; i++) {
        if(apariciones[i]) {
            (*count)++;
            userWord[i] = actualWord[i];

        }
    }
}

char askLetter() {
    char c=0;
    printf("Ingrese una letra minuscula: ");
    do {
        c = getchar();
    }
    while (!islower(c) && !isalpha(c));
    return c;
}


int jugar(char actualWord[], char userWord[]) {
    int counter = 0;
    for(int i=0;counter < LETRAS &&  i<VIDAS; ) {
        int apariciones[LETRAS] = {0};
        char letra = askLetter();
        int coincide = comparaLetra(letra, actualWord, apariciones);
        if(coincide) {
            printf("La letra %c esta!\n", letra);
            actualizaPalabra(userWord, actualWord, apariciones, &counter);
            printf("%s\n", userWord);
        }
        else {
            i++;
            printf("La letra %c NO esta\n", letra);
            printf("%s\n", userWord);

        }
    }
    return counter/LETRAS;
}

int main() {
    char actualWord[LETRAS+1];
    char userWord[LETRAS+1];
    for(int i=0; i<LETRAS; i++) {
        userWord[i] = '_';
    }
    char almacenPalabras[20][7] = {
        "árboles",
        "amigos",
        "besara",
        "camino",
        "cielos",
        "doctor",
        "escudo",
        "fiesta",
        "golpes",
        "hablan",
        "islote",
        "jovial",
        "kilosa",
        "libros",
        "madres",
        "noches",
        "patria",
        "quesos",
        "rápido",
        "sueños"
    };
    elegirPalabra(almacenPalabras, actualWord);
    // printf("%s\n", actualWord);
    int result = jugar(actualWord, userWord);
    if(result)
        printf("Ganaste, la palabra era: %s", actualWord);
    else
        printf("Perdiste, la palabra era %s", actualWord);
}