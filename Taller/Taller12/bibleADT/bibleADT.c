#include "bibleADT.h"

#define CANT_BOOKS  76


struct tBook {
    char **versicles;
    size_t verseDim;
};

struct bibleCDT {
    struct tBook bible[CANT_BOOKS];
};


bibleADT newBible() {
    return calloc(1, sizeof(struct bibleCDT));
}

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

int addVerse(bibleADT bible, size_t bookNbr, size_t verseNbr, const char * verse) {
    if(bookNbr > 76) {
        return 0;
    }
    if(verseNbr > bible->bible[bookNbr-1].verseDim) { //si el numero de vesiculo es mayor al vector que tengo
        bible->bible[bookNbr-1].versicles = realloc(bible->bible[bookNbr-1].versicles, sizeof(char *)*verseNbr); //agranda la cantidad de versiculos
        for(int i = bible->bible[bookNbr-1].verseDim; i< verseNbr; i++) {
            bible->bible[bookNbr-1].versicles[i] = NULL;
        }
        int tam = strlen(verse);
        bible->bible[bookNbr-1].versicles[verseNbr-1] = realloc(bible->bible[bookNbr-1].versicles[verseNbr-1], sizeof(char)*(tam + 1)); // reserva el espacio para el versiculo nuevo
        strcpy(bible->bible[bookNbr-1].versicles[verseNbr-1], verse);
        bible->bible[bookNbr-1].verseDim = verseNbr;
        return 1;
    }
    if(bible->bible[bookNbr-1].versicles[verseNbr-1] != NULL){ // significa que ya esta escrito ese versiculo
        return 0;
    }
    bible->bible[bookNbr-1].versicles[verseNbr-1] = realloc(bible->bible[bookNbr-1].versicles[verseNbr-1], sizeof(char)*(strlen(verse) + 1)); // reserva el espacio para el versiculo nuevo
    strcpy(bible->bible[bookNbr-1].versicles[verseNbr-1], verse);
    return 1;

}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

char * getVerse(bibleADT bible, size_t bookNbr, size_t verseNbr) {
    if(bookNbr>76 || verseNbr > bible->bible[bookNbr-1].verseDim || bible->bible[bookNbr-1].versicles[verseNbr-1] == NULL)
        return NULL;
    char *toReturn = malloc(sizeof(char)*(1+strlen(bible->bible[bookNbr-1].versicles[verseNbr-1])));
    strcpy(toReturn, bible->bible[bookNbr-1].versicles[verseNbr-1]);
    return toReturn;
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------



void freeBible(bibleADT bible) {
    for(int i=0; i<CANT_BOOKS; i++) {
        if(bible->bible[i].versicles != NULL) {
            for(int k=0; k<bible->bible[i].verseDim; k++) {
                if(bible->bible[i].versicles[k] != NULL) {
                    free(bible->bible[i].versicles[k]);
                }
            }
            free(bible->bible[i].versicles);
        }
    }
    free(bible);
}

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
