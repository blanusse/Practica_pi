#include <stdio.h>
#define ELAPSED(a, b, c, d)     ((a)-(c))*60 + ((b)-(d))


int main() {
    int h1=2, m1=30, h2=2, m2=15;
    printf("%d minutos\n", ELAPSED(h1, m1, h2, m2));
    return 0;
}