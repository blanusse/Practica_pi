#include "dictADT.h"

#include <ctype.h>
#include <string.h>
#define LETTERS     ('z'-'a'+1)
#define WORD_TO_INDEX(s)   (tolower((s)) - 'a')
#define BLOCK   2

struct tWord {
    char *word;
    char *def;
    size_t defLength;
    size_t wordLength;
    struct tWord *nextWord;
};

typedef struct tWord *wordList;

typedef struct dictElem {
    wordList firstWord;
    size_t cantWords;
}dictElem;


struct dictCDT {
    dictElem words[LETTERS];
    size_t totalWords;
};
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
static char * copyStr(char *target, const char *source, size_t *size ){
    int i, k = *size;
    for(i = 0; source[i]; i++) {
        if((k+i)%BLOCK == 0) {
            target = realloc(target, k+i+BLOCK);
        }
        target[k+i] = source[i];
    }
    *size += i;
    return target;
}

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

dictADT newDict(void) {
    return calloc(1, sizeof(struct dictCDT));
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

static wordList addDefinitionRec(wordList currentWord, const char * word, const char * deff, int *flag) {
    int c;
    if(currentWord == NULL || (c = strcmp(word, currentWord->word)) < 0) {
        wordList newWord = malloc(sizeof(struct tWord));

        newWord->wordLength = strlen(word);
        newWord->word = malloc(sizeof(char) * (newWord->wordLength + 1));
        strcpy(newWord->word, word);

        newWord->defLength = 0;
        newWord->def = copyStr(NULL, deff, &(newWord->defLength));
        newWord->nextWord = currentWord; // lo agrego antes de la palabra actual

        *flag = 1;
        return newWord;
    }
    if(c == 0) {
        currentWord->def = copyStr(currentWord->def, deff, &(currentWord->defLength));
        return currentWord;

    }
    currentWord->nextWord = addDefinitionRec(currentWord->nextWord, word, deff, flag);
    return currentWord;
}

void addDefinition(dictADT dict, const char * word, const char * deff) {
    if(word == NULL || deff == NULL) {
        return;
    }
    int flag = 0; //flag para ver si se agrego una palabra o no
    int idx = WORD_TO_INDEX(word[0]);
    dict->words[idx].firstWord = addDefinitionRec(dict->words[idx].firstWord, word, deff, &flag);
    dict->totalWords+=flag;
    dict->words[idx].cantWords+=flag;
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

static char * getDeffRec(const wordList currentWord, const char * word) {
    int c;
    if(currentWord == NULL || (c = strcmp(word, currentWord->word)) < 0) { // no encontro la palabra
        return NULL;
    }
    if(c == 0) { // encontro la palabra
        char * toReturn = malloc(sizeof(char) * (currentWord->defLength + 1));
        int i=0;
        for(; i<currentWord->defLength; i++) {
            toReturn[i] = currentWord->def[i];
        }
        toReturn[i] = 0;
        return toReturn;
    }
    return getDeffRec(currentWord->nextWord, word);
}



char * getDeff(const dictADT dict, const char * word) {
    if(word == NULL)
        return NULL;
    int idx = WORD_TO_INDEX(word[0]);
    return getDeffRec(dict->words[idx].firstWord, word);

}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------




char ** wordsBeginWith(const dictADT dict, char letter, size_t * dim) {
    int idx = WORD_TO_INDEX(letter);
    if(dict->words[idx].cantWords == 0) {
        *dim = 0;
        return NULL;
    }
    *dim = dict->words[idx].cantWords; //cantidad de palabras con la letra
    char **toReturn = malloc(sizeof(char *) * (*dim)); // reserva el lugar para las palabras
    wordList aux = dict->words[idx].firstWord; //define un aux que apunte a la primer palabra con esa letra
    for(int i = 0; i < *dim;i++) {
        toReturn[i] = malloc(sizeof(char) * (strlen(aux->word) + 1));
        strcpy(toReturn[i], aux->word);
        aux = aux->nextWord;
    }
    return toReturn;

}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

char ** words(const dictADT dict, size_t * dim) {
    if(dict->totalWords == 0) {
        return NULL;
    }
    *dim = dict->totalWords; // cantidad de palabras totales
    char **toReturn = malloc(sizeof(char*) *(*dim)); //reserva el espacio para todas las palabras
    int count = 0;
    for(int i=0; i<LETTERS; i++) {
        wordList aux = dict->words[i].firstWord;
        for(int k = 0; k < dict->words[i].cantWords; k++) {
            toReturn[count] = malloc(sizeof(char) * (strlen(aux->word) + 1));
            strcpy(toReturn[count], aux->word);
            count++;
            aux = aux->nextWord;
        }
    }
    return toReturn;
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

static wordList removeWordRec(wordList currentWord, const char * word, int *flag) {
    int c;
    if(currentWord == NULL || (c = strcmp(word, currentWord->word)) < 0) { // no encontro la palabra
        return NULL;
    }
    if(c == 0) {
        free(currentWord->def);
        free(currentWord->word);
        wordList aux = currentWord->nextWord;
        free(currentWord);
        *flag = 1;
        return aux;
    }
    currentWord->nextWord = removeWordRec(currentWord->nextWord, word, flag);
}

void removeWord(dictADT dict, const char * word) {
    int idx = WORD_TO_INDEX(word[0]);
    int flag = 0;
    removeWordRec(dict->words[idx].firstWord, word, &flag);
    dict->words[idx].cantWords -=flag;
    dict->totalWords -= flag;
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

void freeDictRec(wordList currentWord) {
    if(currentWord == NULL)
        return;
    wordList aux = currentWord->nextWord;
    free(currentWord->def);
    free(currentWord->word);
    free(currentWord);
    freeDictRec(aux);
}

void freeDict(dictADT dict) {
    for(int i=0; i<LETTERS; i++) {
        freeDictRec(dict->words[i].firstWord);
    }
    free(dict);
}