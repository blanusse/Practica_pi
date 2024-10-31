#include "phrasesADT.h"

#include <string.h>

struct tPhrase {
    char *frase; //frase
    int key; //key
    struct tPhrase *tail; //puntero a siguiente frase, ordenado por key de menor a mayor
};
typedef struct tPhrase *tList;

struct phrasesCDT {
    tList phraseList; //puntero a lista  de tPhrase
    size_t phraseDim; //cantidad de palabras
    size_t minKey; //key minima
    size_t maxKey; //key maxima
};



//---------------------------------------------------//////\\\\\\-------------------------------------------------------------------

phrasesADT newPhrasesADT(size_t keyFrom, size_t keyTo) {
    if(keyFrom > keyTo)
        return NULL;
    phrasesADT toReturn = malloc(sizeof(struct phrasesCDT));
    toReturn->phraseDim = 0;
    toReturn->phraseList = NULL;
    toReturn->minKey = keyFrom;
    toReturn->maxKey = keyTo;
    return toReturn;
}
//---------------------------------------------------//////\\\\\\-------------------------------------------------------------------

void freePhraesRec(tList list) {
    if(list == NULL)
        return;
    tList aux = list->tail;
    free(list->frase);
    free(list);
    freePhraesRec(aux);
}

void freePhrases(phrasesADT ph) {
    freePhraesRec(ph->phraseList);
    free(ph);
}
//---------------------------------------------------//////\\\\\\-------------------------------------------------------------------

static tList putRec(tList list, size_t key, const char * phrase, int *flag, size_t *dim) {
    if(list == NULL) { //significa que no estaba, entonces lo agrego al final
        tList newPhrase = malloc(sizeof(struct tPhrase));
        int tam = strlen(phrase);
        newPhrase->frase = malloc(sizeof(char)*(tam+1));
        strcpy(newPhrase->frase, phrase);
        newPhrase->key = key;
        newPhrase->tail = list;
        *flag = 1;
        (*dim)++;
        return newPhrase;
    }
    if(key == list->key) { //significa que ya esta esa key, entonces la reemplazo y no agranda la dimension
        int tam = strlen(phrase);
        list->frase = realloc(list->frase, sizeof(char) * (tam+1));
        strcpy(list->frase, phrase);
        (*flag) = 1; //se cambio la palabra
        return list;
    }
    if(key < list->key) { //encontro el lugar, y deberia ir antes del tPhrase actual
        tList newPhrase = malloc(sizeof(struct tPhrase));
        int tam = strlen(phrase);
        newPhrase->frase = malloc(sizeof(char)*(tam+1));
        strcpy(newPhrase->frase, phrase);
        newPhrase->key = key;
        newPhrase->tail = list;
        *flag = 1;
        (*dim)++;
        return newPhrase;
    }
    list->tail = putRec(list->tail, key, phrase, flag, dim);
}

int put(phrasesADT ph, size_t key, const char * phrase) {
    if(key < ph->minKey || key > ph->maxKey)
        return 0;
    int flag =0;
    ph->phraseList = putRec(ph->phraseList, key, phrase, &flag, &ph->phraseDim);
    return flag;
}
//---------------------------------------------------//////\\\\\\-------------------------------------------------------------------

static char * getRec(const tList list, size_t key) {
    if(list ==NULL || list->key > key) { //no la encontro, entonces devuelve NULL
        return NULL;
    }
    if(list->key == key) { //encontro la key, entonces devuelvo la frase
        int tam = strlen(list->frase);
        char *toReturn = malloc(sizeof(char)*(tam+1));
        strcpy(toReturn, list->frase);
        return toReturn;
    }
    return getRec(list->tail, key);
}

char * get(const phrasesADT ph, size_t key) {
    if(key < ph->minKey || key > ph->maxKey) // si no esta en los parametros de key
        return NULL;
    return getRec(ph->phraseList, key);
}
//---------------------------------------------------//////\\\\\\-------------------------------------------------------------------

size_t size(const phrasesADT ph) {
    return ph->phraseDim;
}
//---------------------------------------------------//////\\\\\\-------------------------------------------------------------------

static char * concatAllRec(const tList list, char *toReturn, int tamToRet) {
    if(list == NULL) { //termina el vector
        return toReturn;
    }
    tamToRet +=strlen(list->frase);
    toReturn = realloc(toReturn, (tamToRet+1)*sizeof(char));
    strcat(toReturn, list->frase);
    return concatAllRec(list->tail, toReturn, tamToRet);



}

char * concatAll(const phrasesADT ph) {
    // if(ph->phraseDim == 0)
    //     return NULL;
    char *toReturn = calloc(1, sizeof(char));
    return concatAllRec(ph->phraseList, toReturn, 0);
}
//---------------------------------------------------//////\\\\\\-------------------------------------------------------------------

char * concatRec(const tList list, char *toReturn,int tamToRet, size_t from, size_t to) {

    if(list == NULL || list->key > to) {
        return toReturn;
    }
    if(list->key<from) {
        return concatRec(list->tail, toReturn, tamToRet, from, to);
    }
    tamToRet += strlen(list->frase);
    toReturn = realloc(toReturn, (tamToRet+1)*sizeof(char));
    strcat(toReturn, list->frase);
    return concatAllRec(list->tail, toReturn, tamToRet);
}

char * concat(const phrasesADT ph, size_t from, size_t to) {
    if(from < ph->minKey || to > ph->maxKey)
        return NULL;
    char *toReturn = calloc(1, sizeof(char));
    return concatRec(ph->phraseList, toReturn,0, from, to);
}
