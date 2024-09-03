#include <stdio.h>
#include <assert.h>

#define DIM     9
#define DIMBLOQUE   3

int seRepiteVector (int r[]) {
    int repetido = 0;
    for(int i = 0; i<DIM && repetido == 0; i++)
        for (int k = 1+i; k<DIM && repetido == 0; k++) {
            if (r[i] == r[k])
                repetido = 1;
        }
    return repetido;
}

void columna (int a[DIM][DIM], int r[DIM], int columnaN) {
    for(int i=0; i<DIM; i++) {
        r[i] = a[i][columnaN];
    }
}

int sudokuSolver(int a[][DIM]) {
    int error = 0;
    for(int i=0; i<DIM && error == 0; i++) {
        if (seRepiteVector(a[i])) {
            error = 1;
        }
        int aux[DIM] = {0};
        for(int k = 0 ;k<DIM; k++) {
            aux[k] = a[k][i];
            if (a[k][i] >9 || a[k][i] < 1)
                error = 1;
        }
        if (seRepiteVector(aux))
            error = 1;
    }
    for(int j = 0; j<DIM && error == 0; j +=3) {
        for(int h = 0; h<DIM && error == 0; h += 3) {
            int aux[DIM], c = 0;
            for(int t = 0+h; t < DIMBLOQUE + h; t++) {
                for(int m = 0+j; m < DIMBLOQUE + j; m++) {
                    aux[c] = a[t][m];
                    c++;
                }
            }
            if (seRepiteVector(aux))
                error = 1;
        }
    }



    return !error;
}



int main(void) {
    // Una matriz vacía no es solución
    int sudoku[DIM][DIM] = {{0}};

    assert(sudokuSolver(sudoku)==0);

    int sudoku2[DIM][DIM] = {
        {3,8,1,9,7,6,5,4,2},
        {2,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
    };

    assert(sudokuSolver(sudoku2)==1);

    int sudoku3[DIM][DIM] = {
        {2,8,1,9,7,6,5,4,2},
        {3,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
    };

    assert(sudokuSolver(sudoku3)==0);

    // Cuando se tomó este ejercicio en un parcial, en una de las respuestas
    // sólo chequeaban que la suma de cada fila, columna y cuadrado fuera 45
    int sudoku4[DIM][DIM] = {
        {5,5,5,5,5,5,5,5,5},
        {5,5,5,5,5,5,5,5,5},
        {5,5,5,5,5,5,5,5,5},
        {5,5,5,5,5,5,5,5,5},
        {5,5,5,5,5,5,5,5,5},
        {5,5,5,5,5,5,5,5,5},
        {5,5,5,5,5,5,5,5,5},
        {5,5,5,5,5,5,5,5,5},
        {5,5,5,5,5,5,5,5,5}
    };

    assert(sudokuSolver(sudoku4)==0);

    int sudoku5[DIM][DIM] = {
        {3,8,1,9,7,6,5,4,12},
        {2,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
    };

    assert(sudokuSolver(sudoku5)==0);
    printf("OK!");

    return 0;
}


/*

int main() {

    //int r[] = {0, 1, 3, 4, 5, 6, 7, 9, 9};
    //printf("%d", seRepiteVector(r));
    int sudoku2[DIM][DIM] = {
        {3,8,1,9,7,6,5,4,2},
        {2,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
    };

    int r[DIM];
    //columna(sudoku2, r, 2);
    printf("%d", sudokuSolver(sudoku2));
}
*/