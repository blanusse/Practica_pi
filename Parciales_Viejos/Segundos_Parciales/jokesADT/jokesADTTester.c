#include "jokesADT.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>


int main(void) {
    jokesADT jokes = newJokes();

    assert(categories(jokes)==NULL);
    assert(categoriesCount(jokes)==0);
    addCategory(jokes, "tontos");

    addCategory(jokes, "racistas");

    addCategory(jokes, "tontos");   // no la agrega

    assert(categoriesCount(jokes)==2);

    char ** cat = categories(jokes);
    assert(strcmp("racistas", cat[0])==0);
    assert(strcmp("tontos", cat[1])==0);
    free(cat[0]);
    free(cat[1]);
    free(cat);

    addJoke(jokes, "tontos", "Que hacen las hormigas cuando salen del jardin? Van a la escuela primaria");
    addJoke(jokes, "tontos", "Como pasa Superman por la multitud? Con supermiso.");

    // Este no lo agrega porque no esta la categoria
    addJoke(jokes, "politica", "Van dos politicos en un helicoptero....");

    char * silly = joke(jokes, "suegras");
    assert(silly==NULL);

    // Tiene que ser alguno de los dos chistes tontos
    for(int i=0; i < 10; i++) {
        silly = joke(jokes, "tontos");
        assert(strncmp(silly, "Como", 4)==0 || strncmp(silly, "Que ", 4)==0);
        free(silly);
    }

    freeJokes(jokes);
    puts("OK!");
    return 0;
}

