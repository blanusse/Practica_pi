#include <stdio.h>
# define MAXIMO2(a, b, c) ((a)>(b))? ((c)=(a)) : ((c)=(b))
# define MAXIMO3(a, b, c) (a)>(b)? MAXIMO2(a,c,b) : MAXIMO2(b,c,a)

int main(void) {
    int x= 3234, y=234, z=12;
    printf("%d", MAXIMO3(x, y, z));
    return 0;
}