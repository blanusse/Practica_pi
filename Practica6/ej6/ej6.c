#include <stdio.h>
#include "../../Lib/random.h"
#define DIM 30
#include <assert.h>

int shuffle(int v[], int dim) {
    randomize()
    for(int i = 0; i<dim; i++) {
        int random = randInt(i, dim-1);
        int aux = v[i];
        v[i] = v[random];
        v[random] = aux;
    }
}





int main(void) {
    int v[DIM];
    randomize();

    for(int i=0; i<DIM; i++) {
        v[i] = -10 + i*2;
    }
    shuffle(v,DIM);

    puts("Vamos a imprimir el vector, debería estar desordenado");
    for(int i=0; i<DIM; i++) {
        printf("%03d\t", v[i]);
    }
    putchar('\n');

    int aux=v[0];
    puts("A continuación desordeamos un vector vacío, no debería fallar");
    shuffle(v,0);
    assert(v[0]==aux);

    return 0;
}
