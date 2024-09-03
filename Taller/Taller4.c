#include <stdio.h>
#include "../Lib/random.h"
#include "../Lib/getnum.h"
#include <assert.h>

#define DIM 10




//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
//EJ1 TALLER 4

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
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
//EJERCICIO 2 TALLER 4
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
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
//EJERCICIO 3 TALLER 4
/*
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
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

//EJERCICIO 4 TALLER 4
int interseccion (const int a[], int dimA,const int b[], int dimB, int r[]) {
    int c=0;
    for(int i=0; i<dimA; i++)

        for(int k=0; k<dimB; k++) {

            if(a[i] == b[k]) {
                r[c] = a[i];
                c++;
            }
        }
    return c;
}
int
main(void) {
    // Prueba para interseccion de desordenados
    int a[] = {7,9,3,5,15};
    int b[] = {5,6,7,9,8};
    int ayb[5];
    int aybDim = interseccion(a, 5, b, 5, ayb);
    assert(aybDim == 3);
    for(int i = 0; i < aybDim; i++) { // Debería obtenerse 5, 7 y 9 en cualquier orden
        printf("%d ", ayb[i]);
    }

    //    // Prueba para interseccion de ordenados (y también desordenados)
        int c[] = {3,5,7,9,15};
        int d[] = {5,6,7,8,9};
        int cyd[5];
        int cybDim = interseccion(c, 5, d, 5, cyd);
        assert(cybDim == 3);
        assert(cyd[0] == 5);
        assert(cyd[1] == 7);
        assert(cyd[2] == 9);

    printf("\nOK!");
    return 0;
}