#ifndef TEORICAS_C_VECTAD_H
#define  TEORICAS_C_VECTAD_H
#include <stdlib.h>

typedef struct vecCDT *vecADT;
typedef int elemType;

//Crea un nuevo vecADT
vecADT newVec(void);

//Almacena un elemento en la posicion indicada
void putElem(vecADT, size_t, elemType);

//Devuelve 1 si se encontro el elemento y lo guarda en un puntero de entrada-salida
int getElem(vecADT, size_t, elemType*);

//Retorna 1 si el elemento estaba y lo "elimina"
int removeElem(vecADT, size_t);

//Retorna la cantidad de elementos
int elemCount(vecADT);

//Libera t.odo el vecADT
void freeVec(vecADT);


#endif
