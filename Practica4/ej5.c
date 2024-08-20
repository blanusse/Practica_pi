#include <stdio.h>
# define MAXIMO2(a, b, c) ((a)>(b))? ((c)=(a)) : ((c)=(b))

int main(void) {
    int a=23, b=4, c=5;
    MAXIMO2(a,b, c);
    printf("%d", c);
    return 0;
}