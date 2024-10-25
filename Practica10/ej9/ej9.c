#include <stdio.h>
#include <assert.h>
#include "../../lib/list.h"


typedef struct nodeBrief * tListBrief;

typedef struct nodeBrief {
		int head;
		size_t count;
		struct nodeBrief * tail;
	} tNodeBrief;

tListBrief comprimeList(tList l) {
	if(l==NULL)
		return NULL; // si termina la lista retorna NULL

	tListBrief newList = malloc(sizeof(tNodeBrief)); // crea una nueva lista ListBrief

	newList->head = l->head;

	if(l->tail == NULL || l->head != l->tail->head) { // si encontro el ultimo elemento o se deja de repetir
		newList->count = 1;							// devuelve 1 en la cuenta y pone en tail el siguiente
		newList->tail = comprimeList(l->tail);
	}

	else if(l->head == l->tail->head) {					//Si el siguiente es igual, crea nodos nuevos hasta que deje de pasar
		tListBrief newList2 = comprimeList(l->tail);    //Si se sigue repitiendo, se aumenta la cuenta
		newList->count = newList2->count + 1;			// y el tail se pausa hasta que deje de repetirse
		newList->tail = newList2->tail;
		free(newList2);			//se libera el auxiliar
	}
	return newList;
}



void freeListBrief(tListBrief lb) {
	if ( lb == NULL)
		return;
	freeListBrief(lb->tail);
	free(lb);
}



int main(void) {

	int v[] = {1,1,2,3,3,3,3,3,10,100,100,998};
	tList list = fromArray(v, sizeof(v)/sizeof(v[0]));
	tListBrief bf = comprimeList(list);

	tListBrief aux = bf;
	assert(aux->head ==1 && aux->count == 2);

	aux = aux->tail;
	assert(aux->head ==2 && aux->count == 1);

	aux = aux->tail;
	assert(aux->head ==3 && aux->count == 5);

	aux = aux->tail;
	assert(aux->head ==10 && aux->count == 1);

	aux = aux->tail;
	assert(aux->head ==100 && aux->count == 2);

	aux = aux->tail;
	assert(aux->head ==998 && aux->count == 1);

	aux = aux->tail;
	assert(aux == NULL);

	freeList(list);
	freeListBrief(bf);

	printf ("OK!\n");
	return 0;
}