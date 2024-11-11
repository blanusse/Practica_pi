#include "hangmanADT.h"
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


int main() {
    hangmanADT h = newHangman(3);	// Los níveles válidos serán 1, 2 y 3
    assert(size(h, 1) == 0); // -> Retorna 0
    assert(size(h, 4) == -1); // -> Retorna -1


    char * firstWords[] = {"ingenieria", "informatica", NULL};
    assert(addWords(h, firstWords, 1) == 2); // -> Retorna 2
    assert(size(h, 1) == 2); // -> Retorna 2
    word(h, 1); // -> Retorna “ingenieria” o “informatica”
    words(h, 1); // -> Retorna {“ingenieria”, “informatica”, NULL}
    // También podría retornar {“informatica”, “ingenieria”,  NULL}


    assert(addWords(h, firstWords, 1) == 0); // -> Retorna 0


    assert(addWords(h, firstWords, 5) == -1); // -> Retorna -1
    assert(size(h, 5) ==-1); // -> Retorna -1
    assert(word(h, 5) == NULL); // -> Retorna NULL
    assert(words(h, 5) == NULL); // -> Retorna NULL;
    words(h, 2); // -> Retorna {NULL}


    char * secondWords[] = {"programacion", NULL};
    assert(addWords(h, secondWords, 3) == 1); // -> Retorna 1
    assert(size(h, 3) == 1); // -> Retorna 1
    word(h, 3); // -> Retorna “programacion”
    words(h, 3); // -> Retorna {“programacion”, NULL}




    // Ejemplo que muestra cómo se copian las palabras en el TAD
    char v[20] = "cazador";
    char * thirdWords[] = { v, NULL};
    assert(addWords(h, thirdWords, 2) == 1); // -> Retorna 1


    printf("%s\n", word(h, 2)); // -> Imprime “cazador”


    strcpy(v, "venado");  // En la dirección v ahora hay otro string


    printf("%s\n", word(h, 2)); // -> Imprime “venado”


    char * lastWords[] = { "cazador", "colador", NULL};
    assert(addWords(h, lastWords, 2) == 2); // -> Retorna 2
    freeHangman(h);
    printf("OK!");
    }
