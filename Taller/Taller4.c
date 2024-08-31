#include <stdio.h>
#include "../Lib/random.h"
#include <assert.h>


/*
int lecturaCarac (int letra, int limite) {
    int i=0, c, contador=0;
    while((c = getchar()) != '\n' && i<limite) {
        if (c == letra || letra == toupper(c))
            contador++;
        i++;
    }
    return contador;
}

int main() {
    randomize()
    int letra = randInt('A', 'Z');
    int numero = randInt(1, 256);
    printf("%d\n", numero);
    printf("La letra %c aparece %d veces", letra, lecturaCarac(letra, numero));

}

*/
/*
void shuffle(int a[], int dim) {
    randomize()
    for(int i=0; i < dim; i++) {
        int aux;
        int random = randInt(i, dim-1);
        aux = a[i];
        a[i]= a[random];
        a[random] = aux;
    }
}


void shuffle2(int a[]) {
    randomize()
    for (int i = 0; a[i] != -1 ; i++) {
        int random = randInt(0, i);
        int aux = a[i];
        a[i] = a[random];
        a[random] = aux;
    }
}



int main() {
    int a[] = {3, 1, 5, 7, 2, -1};
    shuffle2(a);
    for(int i=0; a[i] != -1;i++)
        printf("%d", a[i]);
}
*/

int whereIs(int a[], int dim, int num, int b[]) {
    int c=0;
    for(int i = 0; i<dim; i++) {
        if (a[i] == num) {
            b[c] = i;
            c++;
        }
    }
    return c;
}

int
main(void) {
    int v[] = {3,5,5,5,5,6,7,7,8,9,12,15};
    int dim = sizeof(v)/sizeof(v[0]);
    int positions[dim];
    int positionsDim = whereIs(v, dim, 5, positions);
    for(int i = 0; i < positionsDim; i++) {
        printf("%d ", positions[i]);
    }

    assert(positionsDim == 4); // Busco el elemento 5 en v
    assert(positions[0] == 1);
    assert(positions[1] == 2);
    assert(positions[2] == 3);
    assert(positions[3] == 4);

    assert(whereIs(v, 2, 5, positions) == 1); // Busco el elemento 5 en v con dim 2
    assert(positions[0] == 1);

    assert(whereIs(v, 1, 5, positions) == 0); // Busco el elemento 5 en v con dim 1

    assert(whereIs(v, 0, 1, positions) == 0); // Busco el elemento 5 en v con dim 0

    assert(whereIs(v, dim, 20, positions) == 0); // Busco el elemento 20 en v

    printf("\nOK!");
    return 0;
}

/*
int
main(void) {
    int v[] = {3,5,5,5,5,6,7,7,8,9,12,15};
    int dim = sizeof(v)/sizeof(v[0]);
    int positions[dim];
    int positionsDim = whereIs(v, dim, 5, positions);
    for(int i = 0; i < positionsDim; i++) {
        printf("%d ", positions[i]);
    }

    assert(positionsDim == 4); // Busco el elemento 5 en v
    assert(positions[0] == 1);
    assert(positions[1] == 2);
    assert(positions[2] == 3);
    assert(positions[3] == 4);

    assert(whereIs(v, 2, 5, positions) == 1); // Busco el elemento 5 en v con dim 2
    assert(positions[0] == 1);

    assert(whereIs(v, 1, 5, positions) == 0); // Busco el elemento 5 en v con dim 1

    assert(whereIs(v, 0, 1, positions) == 0); // Busco el elemento 5 en v con dim 0

    assert(whereIs(v, dim, 20, positions) == 0); // Busco el elemento 20 en v

    printf("\nOK!");
    return 0;
}
*/