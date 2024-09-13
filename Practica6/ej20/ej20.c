#include <stdio.h>
#include <assert.h>

#define DIM     9
#define DIMBLOCK   3
#define validNum(a)     ((a) > 0 && (a) < 10)


int blockCheck (int a[][DIM] ,int dirX, int dirY) {
    int repeat = 0;
    int aux[DIM] = {0};
    for(int i=0; i<DIMBLOCK && repeat == 0; i++) {
        for(int k=0; k<DIMBLOCK && repeat == 0 && validNum(a[i][k]); k++) {
            int num = a[dirX+i][dirY+k]-1;
            if (aux[num] == 1 || !validNum(a[i][k]))
                repeat = 1;
            aux[num] = 1;
        }
    }
    return repeat;
}

int sudokuSolver(int a[][DIM]) {
    //Me fijo si se repite en las filas
    int error = 0;
    for(int i=0; i<DIM && !error; i++) {
        int aux[DIM] = {0};
        for(int k=0; k<DIM && !error; k++) {
            if (!validNum(a[i][k]))
                error = 1;
            else {
                int num = a[i][k]-1;
                if(aux[num] == 1)
                    error = 1;
                aux[num] = 1;
            }
        }
    }
    //Me fijo si se repite en las columnas
    for(int i = 0; i<DIM && error == 0; i++) {
        int aux[DIM]= {0};
        for(int k=0; k<DIM && error == 0; k++) {
            int num = a[k][i]-1;
            if(aux[num] == 1)
                error = 1;
            aux[num] = 1;

        }
    }
    //Me fijo si se repite en el bloque
    int matDir[DIM][2] = {{0, 0},
                            {3, 0},
                            {6, 0},
                            {0, 3},
                            {3, 3},
                            {6, 3},
                            {0, 6},
                            {3, 6},
                            {6, 6}};
    for(int i = 0; i<DIM && error == 0; i++) {
        if(blockCheck(a, matDir[i][0], matDir[i][1]))
            error = 1;
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


