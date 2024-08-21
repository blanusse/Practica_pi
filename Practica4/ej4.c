#include <stdio.h>
#define SWAP(t,x,y)     {t i=0; \
                            i=x, x=y, y=i; \
                        }
int main(void) {
    float a=2.3,b=1.2;
    SWAP(float, a, b);
    printf("a= %f, b=%f\n", a, b);
    return 0;
}