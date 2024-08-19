#include <stdio.h>
#include "../Lib/getnum.h"
/*
int main(void) {
    int fil=getint("Ingrese un numero: ");
    int col=fil, fijo=fil;
    while (fil!=0) {
        while (col!=0) {
            printf("*");
            col-=1;
        }
        printf("\n");
        col=fijo;
        fil-=1;
    }
}*/

int main() {
    int num = getint("Ingrese un numero: ");
    int ancho=num;
    for(int columna=num; columna != 0; ) {
        if (ancho != 0) {
            printf("*");
            ancho--;
        }
        else {
            printf("\n");
            ancho=num;
            columna--;
        }
    }
}
