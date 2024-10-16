#include <stdio.h>
#include <assert.h>
#include "../../Lib/utillist.h"



int odds1(tList l) {
	if(l == NULL)
		return 1;
	if(l->elem % 2)
		return odds1(l->tail);
	return 0;
}

int odds2(tList l) {
	if(l== NULL || l->elem % 2 == 0)
		return 0;
	return 1 + odds2(l->tail);
}


int sumAll(tList l) {
	if(l==NULL)
		return 0;
	return l->elem + sumAll(l->tail);
}


int
main(void) {

	assert(sumAll(NULL) == 0);
	assert(odds1(NULL) == 1 );
	assert(odds2(NULL) == 0 );

	int v [] = {1, 3, 5, -1, 0, 2, 4, 3};
	tList l1 = fromArray(v, 8);
	assert(sumAll(l1) == 17);
	assert(odds1(l1) == 0);
	assert(odds2(l1) == 0);
	freeList(l1);

	l1 = fromArray(v, 4);
	assert(sumAll(l1) == 8);
	assert(odds1(l1) == 1);
	assert(odds2(l1) == 1);
	freeList(l1);

	l1 = fromArray(v+4, 3);
	assert(sumAll(l1) == 6);
	assert(odds1(l1) == 0);
	assert(odds2(l1) == 0);
	freeList(l1);

	puts("OK!");
	return 0;
}
