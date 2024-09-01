#include <stdio.h>

//Funcion que devuelve en su nombre el producto entre dos vectores
int prodVectores (int dim, int a[], int b[]) {
    int suma=0;
    for(int i=0; i<dim; i++)
        suma += a[i]*b[i];
    return suma;
}

//Funcion que guarda en un vector la columna de una matriz
void colMatriz(int dim, int b[][dim], int r[], int col) {
    int c=0;
    for(int i=0; i<dim; i++) {
        r[c] = b[i][col];
        c++;
    }
}

//funcion que guarda en un vector la fila de una matriz
void filaMatriz(int dim, int a[][dim], int r[], int fila) {
    int c=0;
    for(int i=0; i<dim; i++) {
        r[c] = a[fila][i];
        c++;
    }
}

void multMatriz(int dim, int a[][dim], int b[][dim], int r[dim][dim]) {
    int c=0,j=0;
    for(int i=0; i<dim; i++) {
        for(int k=0; k<dim; k++) {
            int filaA[dim];
            filaMatriz(dim, a, filaA, i);
            int columnaB[dim];
            colMatriz(dim, b, columnaB, k);
            r[c][j] = prodVectores(dim, filaA, columnaB);
            j++;
        }
        c++;
    }
}


int main() {
    int dim = 3;
    int a[3][3] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}
    };
    int b[3][3] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}
    };
    int r[dim][dim];
    multMatriz(dim, a, b, r);
    for(int i =0; i<dim; i++) {
        for(int k=0; k<dim;k++) {
            printf("%d ", r[i][k]);
        }
        printf("\n");
    }
}