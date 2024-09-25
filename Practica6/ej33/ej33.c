#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "../../Lib/random.h"
#include <time.h>
#define ABC     'Z'-'A'+1
#define MAX     100

void shuffle(char a[]) {
    randomize()
    for (int i = 0; a[i]; i++) {
        int random = randInt(0, i);
        char aux = a[i];
        a[i] = a[random];
        a[random] = aux;
    }
}

void crearAlfabeto(char alf[]) {
    char vecAux[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    shuffle(vecAux);
    strcpy(alf, vecAux);
}


void codificar(char text[], char alf[], char res[]) {
    int i=0;
    for(; text[i];i++) {
        if(isalpha(text[i])) {
            int numLetter = toupper(text[i]) - 'A';
            res[i] = alf[numLetter];
        }
        else res[i] = text[i];
    }
    res[i] = 0;
}
void decodificar(char text[], char alf[], char res[] ) {
    int i=0;
    for(; text[i]; i++) {
        if(isalpha(text[i])) {
            int k=0;
            for(; k<ABC && alf[k] != text[i]; k++) {

            }
            res[i] = 'A' + k;
        }
        else res[i] = text[i];
    }
    res[i] = 0;
}





int main(void) {
    char msg[MAX];
    char dest[MAX];
    // Debemos probar con mayusculas, porque siempre decodifica a mayuscuas
    char *s = "MENSAJE A CODIFICAR";
    char *s2 = "Mensaje a codificar";
    char alpha[MAX];
    crearAlfabeto(alpha);
    codificar(s, alpha, msg);
    assert(strlen(s)==strlen(msg));
    assert(strcmp(s, msg) != 0);
    decodificar(msg, alpha, dest);
    assert(strcmp(dest, s) == 0);

    codificar(s2, alpha, msg);
    assert(strlen(s2)==strlen(msg));
    assert(strcmp(s2, msg) != 0);
    decodificar(msg, alpha, dest);
    assert(strcmp(dest, s) == 0);

    puts("OK");
    return 0;
}
