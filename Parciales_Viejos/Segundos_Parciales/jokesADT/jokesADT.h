#include <stdlib.h>

// struct tCategory {
//     char *name;
//     char **jokes;
//     size_t jokesCount;
//     struct tCategory *nextCat;
// };
//
// typedef struct tCategory *categoryList;
//
// struct jokesCDT {
//     categoryList list;
//     size_t catCount;
//
// };

typedef struct jokesCDT * jokesADT;

// Devuelve un nuevo TAD para almacenar y recuperar chistes
jokesADT newJokes();

/* Libera toda la memoria reservada por el ADT */
void freeJokes(jokesADT jokes);

/* Agrega una categoría si es que no estaba
*  Se asume que la categoría sólo contiene minúsculas, no
* es necesario validarlo
*/
void addCategory(jokesADT jokes, const char * category);

/**
* Agrega un nuevo chiste a una categoría. Si la categoría no existe
* entonces no agrega el chiste. No verifica si el chiste está repetido,
* ya sea en la categoría dada o en otra
*/
void addJoke(jokesADT jokes, const char * category, const char * joke);

/*
* Retorna la copia de un chiste para una categoría. Debe elegir al azar
* entre los chistes de la categoría. Si la categoría no existe
* o no tiene chistes retorna NULL
*/
char * joke(jokesADT jokes, const char * category);

/*
* Elimina una categoría y todos los chistes de esa categoría
*/
void deleteCategory(jokesADT jokes, const char * category);

/* Retorna la cantidad de categorías */
size_t categoriesCount(const jokesADT jokes);

/*
* Retorna un vector con una copia de todas las categorías, ordenado
* alfabéticamente. La cantidad de elementos estará dada por la función
* categoriesCount. Si no hay categorías retorna NULL
*/
char ** categories(const jokesADT jokes);




