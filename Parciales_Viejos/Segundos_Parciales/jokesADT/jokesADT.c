#include "jokesADT.h"

#include <string.h>

#define BLOCK	10

struct tCategory {
    char *name;
    char **jokes;
    size_t jokesCount;
    struct tCategory *tail;
};

typedef struct tCategory *categoryList;

struct jokesCDT {
    categoryList list;
    size_t catCount;

};


jokesADT newJokes() {
    return calloc(1, sizeof(struct jokesCDT));
}

void freeJokesRec(categoryList list) {
	if(list == NULL)
		return;
	categoryList aux = list->tail;
	free(list->name);
	for(int i=0; i<list->jokesCount;i++){
		free(list->jokes[i]);
	}
	free(list->jokes);
	free(list);
	freeJokesRec(aux);
}


void freeJokes(jokesADT jokes) {
	freeJokesRec(jokes->list);
	free(jokes);
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

static categoryList addCategoryRec(categoryList list, const char * category, int *flag){
	int c;
	if(list == NULL || (c = strcmp(category, list->name))< 0){
		categoryList new = malloc(sizeof(struct tCategory));
		new->name = malloc(sizeof(char) * (strlen(category) + 1));
		strcpy(new->name, category);
		new->jokes = NULL;
		new->jokesCount = 0;
		new->tail = list;
		*flag = 1;
		return new;
	}
	if(c == 0) {
		*flag = 0;
		return list;
	}
	list->tail = addCategoryRec(list->tail, category, flag);
	return list;
}


void addCategory(jokesADT jokes, const char * category){
	if(category == NULL)
		return;
	int flag = 0;
	jokes->list = addCategoryRec(jokes->list, category, &flag);
	jokes->catCount += flag;
	
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

static categoryList addJokeRec(categoryList cat, const char * joke){
	if(cat->jokesCount % BLOCK == 0) {
		cat->jokes = realloc(cat->jokes, sizeof(char *) * (cat->jokesCount + BLOCK));
	}
	cat->jokes[cat->jokesCount] = malloc(sizeof(char) * (strlen(joke) +1 ));
	strcpy(cat->jokes[cat->jokesCount], joke);
	cat->jokesCount++;
	return cat;
}

static categoryList searchCat(categoryList list, const char * category){
	int c;
        if(list == NULL || (c = strcmp(category, list->name))< 0){
		return NULL;
	}
	if(c == 0){
		return list;
	}
	return searchCat(list->tail, category);
}


void addJoke(jokesADT jokes, const char * category, const char * joke){
	if(category == NULL || joke == NULL)
		return;
	categoryList aux = searchCat(jokes->list, category);
	if(aux == NULL)
		return;
	aux = addJokeRec(aux, joke);
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
static double randNormalize() {
	return rand() / ( (double) RAND_MAX+1);
}

static int randInt(int min, int max) {
	if(min > max) {
		int aux = min;
		min = max;
		max = aux;
	}
	return randNormalize() * (max-min+1) + min;
}

static char * jokeRec(categoryList cat){
	int jokeNum = randInt(0, cat->jokesCount - 1);
	char *toReturn = malloc(sizeof(char) * (strlen(cat->jokes[jokeNum]) + 1));
	strcpy(toReturn, cat->jokes[jokeNum]);
	return toReturn;
}
char * joke(jokesADT jokes, const char * category){
	categoryList aux = searchCat(jokes->list, category);
	if(aux == NULL)
		return NULL;
	return jokeRec(aux);
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

void deleteCategory(jokesADT jokes, const char * category);
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

size_t categoriesCount(const jokesADT jokes){
	return jokes->catCount;
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

char ** categoriesRec(categoryList list, size_t dim){
	char **toReturn = malloc(sizeof(char *)*dim);
	categoryList aux = list;
	for(int i=0; i<dim; i++) {
		toReturn[i] = malloc(sizeof(char) * (strlen(aux->name) + 1));
		strcpy(toReturn[i], aux->name);
		aux = aux->tail;
	}
	return toReturn;
}

char ** categories(const jokesADT jokes){
	if(jokes->catCount == 0)
		return NULL;
	return categoriesRec(jokes->list, jokes->catCount);
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------



