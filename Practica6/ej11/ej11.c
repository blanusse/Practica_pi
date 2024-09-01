#include <stdio.h>
#include <assert.h>

#define MAXCOL 10

void ordenaMatriz (int mat[][MAXCOL], int fil, int col, int n) {
    int contador =0;
    while (contador != fil) {
        for(int i = 0; i<fil; i++) {
            for(int j=0; j<fil; j++) {
                if(mat[i][n-1] < mat[j][n-1])
                    mat[contador][n-1] = mat[i][n-1];
            }
        }
        contador++;
    }
}




int checkVector(const int v1[], const int v2[], int dim) {
    for(int i=0; i < dim; i++)
        if ( v1[i] != v2[i])
            return 0;
    return 1;
}

int main() {
    int v1[][] = {{1, 2, 3},
            {7, 9, 10},
            {4, 5, 6}};
    ordenaMatriz(v1, 3, 3, 1);


}


/*
int main(void) {
    int m[][MAXCOL] = { {1, 2, 3, 4, 5},
              {6, 2, 8, 9, 10},
              {3, 5, 8, 2, 1},
              {8, 7, 3, 6, 7}};

    int m2[][MAXCOL] = { {1, 2, 3, 4, 5},
              {6, 2, 8, 9, 10},
              {3, 5, 8, 2, 1},
              {8, 7, 3, 6, 7}};

    // La matriz no cambia
    ordenaMatriz(m, 4, 5, 2);

    for(int i=0; i < 4; i++)
        assert(checkVector(m[i], m2[i], 5));

    ordenaMatriz(m, 4, 5, 1);
    assert(checkVector(m[0], m2[0], 5));
    assert(checkVector(m[1], m2[2], 5));
    assert(checkVector(m[2], m2[1], 5));
    assert(checkVector(m[3], m2[3], 5));

    ordenaMatriz(m, 4, 5, 3);
    assert(checkVector(m[0], m2[0], 5) || checkVector(m[0], m2[3], 5));
    assert(checkVector(m[1], m2[0], 5) || checkVector(m[1], m2[3], 5));
    assert(checkVector(m[2], m2[1], 5) || checkVector(m[2], m2[2], 5));
    assert(checkVector(m[3], m2[1], 5) || checkVector(m[3], m2[2], 5));

    printf("OK!\n");
    return 0;
}