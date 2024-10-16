#include <stdio.h>
#define MAX     5

struct tPrueba {
    int x;
    int y;
};

typedef struct tPrueba tMatriz[MAX];

int main() {
    tMatriz matriz;
    matriz[1].x = 11;
    matriz[1].y = 1;
    matriz[3].x = 33;
    matriz[3].y =3;

    printf("%d\t%d\n", matriz[1].x, matriz[1].y);
    printf("%d\t%d\n", matriz[3].x, matriz[3].y);

    struct tPrueba swap;
    swap = matriz[1];
    matriz[1] = matriz[3];
    matriz[3] = swap;
    printf("%d\t%d\n", matriz[1].x, matriz[1].y);
    printf("%d\t%d", matriz[3].x, matriz[3].y);
}