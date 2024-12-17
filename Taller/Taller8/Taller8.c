
#include <stdio.h>
#include <stdlib.h>
#include "../Lib/getnum.h"
#include "../Lib/random.h"

#define TOTAL_ITEMS 2
#define MAX_LONG 10
#define MOV_BLOCK   10
#define CHUNK 15

// int obtenerAprobados(char *arrNombres[], int tam, char *aprobados[], int notas[]) {
//     int k=0;
//     for(int i=0; i<tam; i++) {
//         if(notas[i] >= 4) {
//             aprobados[k++] = arrNombres[i];
//         }
//     }
//     return k;
// }
//
// void mostrarNombres(char *arrNombres[], size_t n) {
//     for(int i=0; i<n; i++) {
//         printf("%s\t", arrNombres[i]);
//     }
//     printf("\n");
// }
//
// int
// main(void) {
//     char *arrNombres[] = {"anita", "pepe", "fabi", "carlos", "tere"};
//     char *aprobados[5];
//     int notas[] = {3, 4, 8, 10, 1};
//     int tam, tamApro;
//     tam = sizeof(arrNombres) / sizeof(char *);
//     mostrarNombres(arrNombres, tam);
//     tamApro = obtenerAprobados(arrNombres, tam, aprobados, notas);
//     printf("Aprobados:\n");
//     mostrarNombres(aprobados, tamApro);
//     return 0;
// }

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

// typedef struct {
//     int codigo;
//     char desc[MAX_LONG];
//     float precio;
// } tItem;
//
// tItem leerItem() {
//     tItem item;
//     item.codigo = getint("Codigo: ");
//     item.precio = getfloat("Precio: ");
//     printf("Descripcion:");
//     fgets(item.desc, MAX_LONG, STDIO);
//     return item;
// }
//
//
// typedef tItem tFactura[TOTAL_ITEMS];
//
// void cargar(tFactura fact, int cant);
//
// void cargar(tFactura f, int cant) {
//
//     tItem item;
//     item.codigo = getint("Codigo: ");
// }
//
// float importe(tFactura fact, int cant);
//
// int
// main(void) {
//     tFactura f;
//     cargar(f, TOTAL_ITEMS);
//     printf("%.2f", importe(f, TOTAL_ITEMS));
//     return 0;
// }


//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

typedef struct {
    int x;
    int y;
}tPunto2D;

typedef tPunto2D *tPosiciones;

tPunto2D movAleatorio() {
    tPunto2D mov;
    mov.x = randInt(-3, 3);
    mov.y = randInt(-3, 3);
    return mov;
}



int main() {
    randomize();

    int i=1;
    tPosiciones vecPos = calloc(CHUNK, sizeof(tPunto2D));
    int found = 0;
    for(; !found && i <20;i++) {
        if(i%CHUNK == 0) {
            vecPos = realloc(vecPos,(CHUNK+i) * sizeof(tPunto2D));
        }

        tPunto2D movAleat = movAleatorio();
        vecPos[i].x = vecPos[i-1].x + movAleat.x;
        vecPos[i].y = vecPos[i-1].y + movAleat.y;
        if(vecPos[i].x == 0 && vecPos[i].y == 0) {
            found = 1;
        }

    }
    for(int k=0; k<i; k++) {
        printf("%d\t%d\n", vecPos[k].x, vecPos[k].y);
    }
    printf("Fueron  %d movimientos", i);

    free(vecPos);
}






