#include <stdio.h>
#define MIN(a, b)   (a)>(b) ? (b) : (a)
#define MAX(a, b)   (a)<(b) ? (b) : (a)


int mcd(int a, int b) {
    if(a==1 || b== 1) {
        return 1;
    }
    if(a==0 || b==0)
        return MAX(a, b);

    int modulo = (MAX(a, b)) % (MIN(a, b));
    mcd(MIN(a, b), modulo);
}


int main() {
    printf("%d\n", mcd(3, 15));
}