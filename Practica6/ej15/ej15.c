#include <math.h>
#include <stdio.h>
#include <assert.h>

#define MAX(a, b)       a>b ? a:b
#define MIN(a, b)       a<b ? a:b
#define ALTO 6
#define ANCHO 5
void copiaMatriz(unsigned char a[ALTO][ANCHO], unsigned char b[ALTO][ANCHO]) {
    for(int i=0; i<ALTO; i++) {
        for(int k=0; k<ANCHO; k++)
            b[i][k] = a[i][k];
    }
}
int mediaAritmetica (unsigned char a[ALTO][ANCHO], int fila, int columna, int w) {
    int suma = a[fila][columna];
    int counter = 1;
    for(int i=1; i<(w/2)+1; i++) {
        if(fila-i >= 0) {
            suma += a[fila-i][columna];
            counter++;
        }

        if(fila+i < ALTO) {
            suma += a[fila+i][columna];
            counter++;
        }

        if(columna-i >= 0) {
            suma += a[fila][columna-i];
            counter++;
        }

        if (columna+i < ANCHO) {
            suma += a[fila][columna+i];
            counter++;
        }

        if (fila-i >= 0 && columna-i >= 0) {
            suma += a[fila-i][columna-i];
            counter++;
        }

        if (fila-i >= 0 && columna+i < ANCHO) {
            suma += a[fila-i][columna+i];
            counter++;
        }

        if (fila+i < ALTO && columna-i >= 0) {
            suma += a[fila+i][columna-i];
            counter++;
        }

        if (fila+i < ALTO && columna+i < ANCHO) {
            suma += a[fila+i][columna+i];
            counter++;
        }
    }
    printf("%d\n", counter);
    return suma/counter;
}

int mediaAritmetica2 (unsigned char a[ALTO][ANCHO], int fila, int columna, int w) {
    int mov = (w-1)/2;
    int numFilas = MAX(0, fila-mov);
    int numCol = MAX(0, columna-mov);
    int suma = 0, contador = 0;
    int limFila = MIN(ALTO - 1, fila + mov);
    int limCol = MIN(ANCHO - 1, columna + mov);

    for(int i=numFilas; i<=limFila; i++) {
        for(int k = numCol; k<=limCol; k++) {
            suma += a[i][k];
            contador++;
        }
    }
    return (suma/contador);


}

void suavizar (unsigned char a[ALTO][ANCHO], int w) {
    int aux[ALTO][ANCHO];
    copiaMatriz(a, aux);
    if (w>=3 && w%2) {
        for(int i=0; i<ALTO; i++) {
            for(int k=0; k<ANCHO; k++) {
                a[i][k] = mediaAritmetica2(aux, i, k, w);
            }
        }
    }
}





int equals(unsigned int cols, unsigned char m1[][cols], unsigned char m2[][cols], unsigned int rows) {
    for (int i=0; i < rows; i++) {
        for(int j=0; j < cols; j++) {
            if ( m1[i][j] != m2[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main(void) {
    unsigned char bmp[ALTO][ANCHO] =    {
        {10,10,20,23,24},
        {10,12,18,25,23},
        {12,14,18,26,22},
        {12,14,19,20,22},
        {13,16,19,20,22},
        {14,14,19,21,23}};


    suavizar(bmp, 3);
    unsigned char suave[ALTO][ANCHO] =    {
        {10,13,18,22,23},
        {11,13,18,22,23},
        {12,14,18,21,23},
        {13,15,18,20,22},
        {13,15,18,20,21},
        {14,15,18,20,21}};

    assert(equals(ANCHO, bmp, suave, ALTO));

    // Ahora una con w=5
    unsigned char suave5[ALTO][ANCHO] =    {
        {14,16,17,19,20},
        {14,16,17,18,20},
        {14,16,17,18,20},
        {15,16,17,18,20},
        {15,16,17,18,20},
        {15,16,17,18,19}};

    suavizar(bmp, 5);
    assert(equals(ANCHO, bmp, suave5, ALTO));

    puts("OK!");
    return 0;
}


/*
int main() {
    unsigned char bmp[ALTO][ANCHO] ={
        {10,10,20,23,24},
        {10,12,18,25,23},
        {12,14,18,26,22},
        {12,14,19,20,22},
        {13,16,19,20,22},
        {14,14,19,21,23}};
    suavizar(bmp, 3);
    for(int i=0;i<ALTO; i++) {
        for(int k=0; k<ANCHO; k++)
            printf("%d ", bmp[i][k]);
        printf("\n");
    }

}
*/