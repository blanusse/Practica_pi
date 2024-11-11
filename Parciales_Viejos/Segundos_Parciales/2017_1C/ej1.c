#define BLOCK 	10
#include <stdlib.h>
#include <stdio.h>
#include "../../../Lib/utillist.h"
// struct tNode{
// 	int elem;
// 	struct tNode *tail;
// };
//
// typedef struct tNode *tList;





tList toListRec(int *v){
	if(*v == -1){
		return NULL;
	}
	tList aux = malloc(sizeof(tNode));
	aux->head = *v;
	aux->tail = toListRec(v+1);
	return aux;
}




int main(){

	int v[] = {1, 2, 3, 4, 5, 6, 7, -1};
	tList l = toListRec(v);
	checkElems(l, v, 7);
	printf("OK!");
	freeList(l);
}

