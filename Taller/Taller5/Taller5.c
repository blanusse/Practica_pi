#include <stdio.h>
#include <assert.h>

#define R 0.2989
#define G 0.5870
#define B 0.1140

#define N 3
#define M 5
#define RGB_M (3*M)

#define FILAS 7
#define COLS 6
#define ERROR (-1)


//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

//EJERCICIO 1 - RGB TO GRAY//

//
// void rgbToGray(const unsigned char (rgb[N])[RGB_M], unsigned char grayscale[][M]) {
//     for(int i=0; i<N; i++) {
//         for(int k = 0; k<RGB_M; k+=3) {
//             grayscale[i][k/3] = rgb[i][k] * R + rgb[i][k+1] *G + rgb[i][k+2] * B;
//         }
//     }
// }
//
//
//
// static void assertMatrixEquals(const unsigned char (expected[])[M], const unsigned char (actual[])[M], size_t fils, size_t cols);
//
// int
// main(void) {
//     unsigned char rgbMatrix[][RGB_M] = {
//         {100,200,100,100,180,100,200,100,120,110,123,122,100,120,122},
//         {101,200,105,99,200,100,201,102,118,110,120,120,100,121,122},
//         {100,200,100,100,210,105,200,100,100,120,120,100,100,122,121}
//     };
//     unsigned char grayscaleMatrix[N][M];
//     rgbToGray(rgbMatrix, grayscaleMatrix);
//     unsigned char expectedGrayscaleMatrix[][M] = {
//         {158,146,132,118,114},
//         {159,158,133,116,114},
//         {158,165,129,117,115}
//     };
//     assertMatrixEquals(expectedGrayscaleMatrix, grayscaleMatrix, N, M);
//
//     puts("OK!\n");
//     return 0;
// }
//
// /**
//  * Tester
//  */
// /*
// static void
// assertMatrixEquals(const unsigned char (expected[])[M], const unsigned char (actual[])[M], size_t fils, size_t cols) {
//     for (int i = 0; i < fils; i++) {
//         for (int j = 0; j < cols; j++) {
//             assert(expected[i][j] == actual[i][j]);
//         }
//     }
// }
//
// */
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

//EJERCICIO 2 - CALCULA DIRECCION//



int mov(char mat[][COLS], int alto, int ancho, int x, int y, int direcX, int direcY) {
    int movement = 0;
    for(;y+direcY >= 0 && y+direcY < ancho && x+direcX >= 0 && x+direcX < alto && mat[x+direcX][y+direcY] == '0'; x += direcX, y += direcY, movement++) {

    }
    return movement;
}




int calculaDireccion(char mat[][COLS], int alto, int ancho, int x, int y) {
    if (x < alto && x >= 0 && y<ancho && y >= 0) {
        int movement = 0, maxMov = 0, maxMovFil = -1;
        int matDir[8][2] = {
            {0, 1},
            {-1,1},
            {-1,0},
            {-1, -1},
            {0, -1},
            {1, -1},
            {1, 0},
            {1, 1}
        };
        for(int i = 0; i<8; i++) {
            movement = mov (mat, alto, ancho, x, y, matDir[i][0], matDir[i][1]);
            if (movement > maxMov) {
                maxMov = movement;
                maxMovFil = i;
            }

        }
        return maxMovFil*45;
    }
    return ERROR;
}



int
main(void) {
    char tablero[][COLS] = {
        {'0', '0', '0', '0', '1', '0'},
        {'X', 'X', '0', '0', '0', '0'},
        {'0', '0', '0', '0', 'X', 'X'},
        {'0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', 'X', '0', '0'},
        {'1', '0', '0', 'X', 'X', 'X'}
    };
    int res = calculaDireccion(tablero, FILAS, COLS, 4, 1);
    assert(res == 0 || res == 45);

    assert(calculaDireccion(tablero, FILAS, COLS, 0, 0) == 0);
    assert(calculaDireccion(tablero, FILAS, COLS, 6, 2) == 90);
    assert(calculaDireccion(tablero, FILAS, COLS, 5, 4) == 135);
    assert(calculaDireccion(tablero, FILAS, COLS, 3, 5) == 180);
    assert(calculaDireccion(tablero, FILAS, COLS, 0, 5) == 225);

    res = calculaDireccion(tablero, FILAS, COLS, 3, 2);
    assert(res == 0 || res == 45 || res == 90 || res == 270);

    // Jugador fuera del tablero
    assert(calculaDireccion(tablero, FILAS, COLS, FILAS, COLS) == ERROR);

    printf("OK!\n");
    return 0;
}