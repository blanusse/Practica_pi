#include <stdio.h>


void hanoi(int n, char orig, char aux, char dest) {
    if(n==1)
        printf("Mover %c -> %c\n", orig, dest);
    else {
        hanoi(n-1, orig, dest, aux);
        printf("Mover %c -> %c\n", orig, dest);
        hanoi(n-1, aux, orig, dest);

    }
}