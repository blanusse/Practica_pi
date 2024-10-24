#include <stdio.h>
#include <assert.h>
#include "stackADT.h"


int main(void) {
    stackADT s =newStack();

    push(s, 3);
    push(s, 5);
    push(s, 1);
    assert(!isEmpty(s));
    assert(peek(s) == 1);
    assert(pop(s) == 1);
    assert(peek(s) == 5);
    push(s, 2);
    assert(pop(s) == 2);
    assert(pop(s) == 5);
    assert(pop(s) == 3);
    assert(isEmpty(s));

    puts("OK!");
    return 0;
}