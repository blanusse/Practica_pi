#include <stdio.h>
#include <stdlib.h>

#include "../../../Lib/random.h"


typedef struct node * tList;

typedef struct node {
	int elem;
	struct node * tail;
} TNode;
tList fromArray(const int v[], unsigned int dim ) {
	tList ans = NULL;
	while (dim) {
		tList aux = malloc(sizeof(TNode));
		aux->elem = v[--dim];
		aux->tail = ans;
		ans = aux;
	}
	return ans;

}
int checkElems(const tList list, const int v[], int dim) {
	int i;
	tList aux;
	for(i=0, aux=list; i<dim && aux != NULL; i++, aux = aux->tail) {
		if ( aux->elem != v[i])
			return 0;
	}
	return aux == NULL && i==dim;
}
void freeList(tList list) {
	if ( list == NULL)
		return;
	freeList(list->tail);
	free(list);
}

tList deleteAll(tList a, tList b){

	if(a == NULL || b == NULL){ // significa que ya termino de recorrer a
		return a;
	}
	if(a->elem > b->elem){
		a->tail = deleteAll(a, b->tail);
		return a;
	}
	if(a->elem < b->elem){
		a->tail = deleteAll(a->tail, b);
		return a;
	}
	a->tail = deleteAll(a->tail, b->tail);
}

int main() {
	randomize();
	int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int b[5] = {2, 4, 6, 8, 10};
	int c[5] = {1, 3, 5, 7, 9};
	tList n = fromArray(v, 10);
	tList n2 = fromArray(b, 5);

	deleteAll(n, n2);
	checkElems(n, c, 5);
	printf("%d\n", randInt(0, 1));
	printf("OK!");

	freeList(n);
	freeList(n2);
}



