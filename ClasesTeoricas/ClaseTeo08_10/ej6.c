#include <stdio.h>

void regla(int medio) {
    if(medio == 0)
        return;

    regla(medio/2);
    printf("%d ", medio);
    regla(medio/2);
}

int main() {
    regla(8);
}