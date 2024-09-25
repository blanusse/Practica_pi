#include <stdio.h>
#include <string.h>
#include <assert.h>
#define COLS    4
#define FILS    4
#define MIN(a, b)   a>b ? b: a
#define MAX(a, b)   a<b ? b: a




int arroundCount(char m[][COLS], int posX, int posY) {
    int suma = 0;
    int limCol = MIN(posY+1, COLS-1);
    int limFil = MIN(posX+1, FILS-1);
    int filaIni = MAX(0, posX-1);
    int colIni = MAX(0, posY-1);

    for(int i=filaIni; i<=limFil; i++) {
        for(int k=colIni; k <= limCol; k++) {
            suma += m[i][k];
        }
    }
    return suma - m[posX][posY];
}

//Muy ineficioente, preguntar
void copyMat(char m1[][COLS], char m2[][COLS]) {
    for(int i=0; i<FILS; i++) {
        for(int k=0; k<COLS; k++) {
            m2[i][k] = m1[i][k];
        }
    }
}



int nextStep(char m[][COLS]) {
    int cambios = 0;
    char aux[FILS][COLS];
    for(int i=0; i<FILS; i++) {
        for(int k=0; k<COLS; k++) {
            int vecinos = arroundCount(m, i, k);
            if(m[i][k] == 0 && vecinos == 3) {
                aux[i][k] = 1;
                cambios = 1;
            }
            else if(m[i][k] == 0)
                aux[i][k] = 0;
            else if(m[i][k] == 1 && vecinos != 2 && vecinos != 3) {
                aux[i][k] = 0;
                cambios = 1;
            }
            else if(m[i][k] == 1) {
                aux[i][k] = 1;
            }
        }
    }
    copyMat(aux, m);
    return cambios;

}

// int main() {
//     char cells[FILS][COLS] =
//          { {0,1,0,0},
//            {1,1,1,1},
//            {0,1,1,0},
//            {1,0,0,1} };
//     printf("%d\n", arroundCount(cells, 1, 2));
//     nextStep(cells);
//     for(int i=0; i<FILS; i++) {
//         for(int k=0; k<COLS; k++) {
//             printf("%d ", cells[i][k]);
//         }
//         printf("\n");
//     }
// }



int main(void) {
    char cells[FILS][COLS] =
        { {0,1,0,0},
          {1,1,1,1},
          {0,1,1,0},
          {1,0,0,1} };

    assert(nextStep(cells)==1);

    char expected[FILS][COLS] =
        { {1,1,0,0},
          {1,0,0,1},
          {0,0,0,0},
          {0,1,1,0} };
    for (int i=0; i < 4; i++)
        for(int j=0; j < 4; j++)
            assert(cells[i][j] == expected[i][j]);

    char cells2[FILS][COLS] =
        {{0,1,1,0},
         {0,1,1,0},
         {0,0,0,0},
         {0,0,0,0} };
    assert(nextStep(cells2)==0);

    char expected2[FILS][COLS] =
        { {0,1,1,0},
          {0,1,1,0},
          {0,0,0,0},
          {0,0,0,0} };

    for (int i=0; i < 4; i++)
        for(int j=0; j < 4; j++)
            assert(cells2[i][j] == expected2[i][j]);

    puts("OK!");

    return 0;
}