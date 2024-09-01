#include <stdio.h>
#define COLUMNAS 30
#define FILAS 10

int sum (int mat[][COLUMNAS], int fila, int columna) {

    int suma = mat[fila][columna+1];
    suma += mat[fila][columna-1];
    suma += mat[fila-1][columna];
    suma += mat[fila-1][columna+1];
    suma += mat[fila-1][columna-1];
    suma += mat[fila+1][columna];
    suma += mat[fila+1][columna+1];
    suma += mat[fila+1][columna-1];
    return suma;
}

void graficar (int cielo[][COLUMNAS], int fil, int col) {
    for(int i = 1; i<fil-1; i++) {
        for(int k = 1; k<col-1; k++) {
            if((cielo[i][k] + sum(cielo, i, k))/9 >10)
                printf("*");
            else printf(" ");
        }
        printf("\n");
    }
}



int
main (void) {
    int cielo1[FILAS][COLUMNAS] = {{0}};

    puts("A continuación debe mostrar 8 filas en blanco");

    graficar(cielo1, FILAS, COLUMNAS);
    puts("-----------------------------");


    int cielo2[FILAS][COLUMNAS] = {
        {10, 17, 6, 15, 6, 7, 8, 9, 11, 12, 13, 15, 8, 10, 11, 13, 14, 15, 18, 20, 11, 8, 2, 3, 12, 13, 11, 3, 9, 20},
        {18, 17, 6, 5, 6, 7, 8, 9, 11, 12, 13, 5, 8, 10, 1, 13, 14, 15, 18, 20, 11, 8, 2, 3, 12, 13, 11, 3, 9, 20},
        {10, 15, 16, 15, 6, 17, 8, 19, 11, 12, 13, 1, 8, 10, 11, 1, 14, 15, 18, 20, 11, 8, 2, 3, 12, 23, 11, 3, 9, 20},
        {12, 2, 6, 5, 16, 7, 8, 9, 1, 12, 13, 15, 8, 10, 1, 13, 14, 15, 18, 20, 11, 8, 2, 3, 12, 23, 11, 3, 9, 20},
        {8, 5, 4, 15, 6, 7, 8, 9, 12, 12, 13, 5, 8, 10, 11, 13, 14, 15, 18, 20, 11, 8, 12, 3, 12, 23, 11, 3, 9, 20},
        {20, 19, 18, 15, 16, 7, 8, 9, 11, 12, 13, 15, 18, 10, 11, 13, 14, 15, 18, 20, 11, 8, 12, 3, 12, 23, 11, 3, 9, 20},
        {10, 9, 9, 15, 16, 7, 8, 9, 12, 12, 13, 11, 8, 10, 1, 13, 14, 15, 18, 20, 11, 8, 2, 13, 12, 23, 11, 3, 9, 20},
        {10, 12, 9, 6, 16, 7, 8, 9, 15, 12, 13, 15, 18, 10, 11, 13, 14, 15, 18, 20, 11, 8, 2, 3, 12, 23, 11, 3, 9, 20},
        {10, 7, 9, 15, 6, 7, 8, 9, 11, 12, 13, 15, 8, 10, 1, 10, 14, 15, 18, 20, 11, 8, 2, 3, 12, 23, 11, 3, 9, 20},
        {10, 17, 16, 15, 6, 7, 8, 9, 11, 12, 13, 15, 8, 10, 11, 3, 14, 15, 18, 20, 11, 8, 2, 3, 12, 23, 11, 3, 9, 20},
    };

    puts("A continuación su función debe mostrar esto:");
    puts(" **     **      *****    *");
    puts(" *              *****   ***");
    puts("         *      *****   ***");
    puts("   *     ****  ******   ***");
    puts(" ****    ***   ******   ***");
    puts(" ****   *****  ******   ***");
    puts("   *    *****   *****   ***");
    puts(" **     *****   *****   ***");

    puts("-----------------------------");
    puts("Y muestra esto:");
    graficar(cielo2, FILAS, COLUMNAS);
    puts("-----------------------------");

    return 0;
}

