#include <stdio.h>


int main() {
    int x,y,z;
    z=(y=x)+(x=2);
    printf("%d", z);
    return 0;
}