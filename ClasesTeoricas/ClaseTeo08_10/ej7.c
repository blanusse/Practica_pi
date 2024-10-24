#include <stdio.h>

int branches(int altura, int alturaMin) {
    if(altura<alturaMin)
        return 0;
    return 1 + 2 * branches(altura/2, alturaMin);
}

int main() {
    printf("%d", branches(10, 1));
}