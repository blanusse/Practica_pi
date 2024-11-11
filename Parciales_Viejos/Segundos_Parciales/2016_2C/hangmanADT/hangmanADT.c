#include "hangmanADT.h"
#include "../../../../Lib/random.h"
#define BLOCK 5

typedef struct tLevel{
	size_t levelDim; //cantidad de palabras
	char **words; //palabras

}tLevel;

typedef tLevel *tLevelV;



struct hangmanCDT{
	tLevelV levelVec; //vector de tLevels que va a tener la misma dim que maxLevel	([0] = nivel1, [1] = nivel2 ...)
	size_t maxLevel; // nivel maximo
};


hangmanADT newHangman(unsigned int maxLevel) {
	if(maxLevel < 1)
		return NULL;
	randomize();
	hangmanADT toReturn = malloc(sizeof(struct hangmanCDT));
	toReturn->maxLevel = maxLevel;
	toReturn->levelVec = calloc(maxLevel, sizeof(tLevel));
	for(int i=0; i<maxLevel; i++) {
		toReturn->levelVec[i].words = NULL;
	}
	return toReturn;
}

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------


int addWords(hangmanADT h, char * wordsToAdd[], unsigned int level) {
	if(level < 1 || level > h->maxLevel) {
		return -1;
	}

	int prevDim = h->levelVec[level-1].levelDim;
	for(int i=0;wordsToAdd[i] != NULL; i++){
		int found = 0;

		for(int k=0; !found && k < h->levelVec[level-1].levelDim ; k++) {
			if(strcmp(h->levelVec[level-1].words[k], wordsToAdd[i]) == 0) {
				found = 1;
			}
		}
		if(!found) {
			if(h->levelVec[level-1].levelDim % BLOCK ==0) {
				h->levelVec[level-1].words = realloc(h->levelVec[level-1].words, (h->levelVec[level-1].levelDim + BLOCK)* sizeof(char *));
			}
			h->levelVec[level-1].words[h->levelVec[level-1].levelDim] = wordsToAdd[i];
			h->levelVec[level-1].levelDim++;
		}
	}
	return h->levelVec[level-1].levelDim - prevDim;
}

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

int size(const hangmanADT h, unsigned int level) {
	if(level < 1 || level > h->maxLevel)
		return -1;
	return h->levelVec[level-1].levelDim;
}

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

char * word(const hangmanADT h, unsigned int level) {
	if(level < 1 || level > h->maxLevel)
		return NULL;
	int wordN = randInt(0, h->levelVec[level-1].levelDim-1);
	return h->levelVec[level-1].words[wordN];
		
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------


char ** words(const hangmanADT h, unsigned int level) {
	if(level < 1 || level > h->maxLevel)
		return NULL;
	return h->levelVec[level-1].words;
}

void freeHangman(hangmanADT h) {
	for(int i=0; i<h->maxLevel; i++) {
		free(h->levelVec[i].words);
	}
	free(h->levelVec);
	free(h);
}
