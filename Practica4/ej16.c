#include <stdio.h>
#define DIVISOR(a, b)  ((a)%(b)==0) ? 1 : 0

int main() {
    int a, b=64, c=-32;
    a= DIVISOR(b, c);
    printf("%d\n", a);
    a=DIVISOR(b, c-1);
    printf("%d", a);
    return 0;
}