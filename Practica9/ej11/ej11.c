#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX 10

void cambio(int mat[][MAX], int dim, int fila, int col, int dirX, int dirY) {
    if(fila+dirX >= dim || col+dirY >= dim || fila+dirX < 0 || col+dirY < 0)

        return;

    mat[fila+dirX][col+dirY] = !mat[fila+dirX][col+dirY];

    return cambio(mat, dim, fila+dirX, col+dirY, dirX, dirY);
}

void wrapperCambio(int mat[][MAX],int dim,  int fila, int col) {
    mat[fila][col] = !mat[fila][col];
    int matDir[][4] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    for(int i=0; i<4; i++) {
        cambio(mat, dim, fila, col, matDir[i][0], matDir[i][1]);
    }
}



int main(void) {

    int m[5][MAX] = { {1,0,1,0,1},
                      {0,1,1,1,1},
                      {1,0,0,1,0},
                      {1,1,1,0,1},
                      {0,0,0,0,0}};
    wrapperCambio(m, 5, 1, 2);
    int m2[5][MAX] = { {1,1,1,1,1},
                      {0,1,0,1,1},
                      {1,1,0,0,0},
                      {0,1,1,0,0},
                      {0,0,0,0,0}};
    for(int i=0; i < 5; i++)
        for(int j=0; j<5; j++)
            assert(m[i][j]==m2[i][j]);
    wrapperCambio(m, 5, 1, 2);
    wrapperCambio(m, 5, 1, 2);
    for(int i=0; i < 5; i++)
        for(int j=0; j<5; j++)
            assert(m[i][j]==m2[i][j]);

    printf ("OK!\n");
    return 0;
}