#include <stdio.h>
#include <assert.h>
#define DIVISOR(a, b)  ((a)%(b)==0) ? 1 : 0

int main(void){
    int b = 10, c=3;

    int a;

    a = DIVISOR(b, 0);
    assert(a==0);

    a = DIVISOR(b, c);
    assert(a==0);

    a = DIVISOR(b, c-1);
    assert(a==1);

    a = DIVISOR(b, b == 0 ? 3 : 2);
    assert(a==1);

    a = DIVISOR(-10, 2);
    assert(a==1);

    a = DIVISOR(-10, -2);
    assert(a==1);

    a = DIVISOR(10, -2);
    assert(a==1);

    a = DIVISOR(10, -3);
    assert(a==0);

    puts("OK!");
}