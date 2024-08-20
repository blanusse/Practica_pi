#include <stdio.h>
int main(void) {
    int exponente=1, total=0;
    for(int c=getchar();c==48 || c==49; c=getchar()) {
        int resto=c%2;
        if (resto==0)
            total+=exponente;
        exponente*=2;
    }
    printf("%d", total);
}