#ifndef TEORICAS_C_LISTADT_H
#define TEORICAS_C_LISTADT_H



typedef char * elemType; // lista de palabras
typedef struct listCDT *listADT;
typedef int (*cmp) (elemType, elemType); //typedef que resume el puntero a funcion


//Funcion que crea un puntero a listCDT con t.odo en NULL menos el pFunc
listADT newList(cmp compare);

//Funcion que recibe un listADT y devuelve la cantidad de elementos
int elemCount(listADT);

//Funcion que devuelve 1 si el listADT esta vacio
int isEmpty(const listADT l);

//Funcion que recibe un listADT y un elemento tipo elemType y devuelve 1 si esta en el listADT
int belongs(const listADT l, elemType);

//Recibe un listADT y un elemento y lo agrega si no esta, devuelve 1 si se agrego
int add(listADT l, elemType);

//Recibe un listADT y un elemento y lo elimina si esta, devuelve 1 si se borro
int delete(listADT, elemType);

//Recibe un listADT y libera toda la lista y el listADT
void freeList(listADT);

//Recibe un listADT y lo pasa a vector de elemType
elemType *toArray(const listADT);

//Recibe un listADT y un indice y devuelve un elemento del listADT
elemType getElemAtIndex(const listADT, int);

elemType * select(listADT l, int (*pFunc)(elemType), int *dimRes);
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

void map(listADT, elemType (*funcion)(elemType));
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
//FUNCIONES DE ITERACION

//Inicializa lo necesario para comenzar a iterar
void toBegin(listADT);

//Retorna 1 si hay un proximo elemento y 0 si no
int hasNext(const listADT);

//Devuelve el elemento actual y avanza la lista al proximo elemento (para esto se usa el hasNext)
elemType next(listADT);


#endif
