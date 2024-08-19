#include <stdio.h>
#include "../Lib/getnum.h"

int main(void) {
    int rangoMax=0, rangoMin=0, anterior=0;
    for(char c=1; c>=anterior; c++) {
        anterior=c;
        rangoMax++;
    }
    for (char c=-1; c<=anterior; c--) {
        anterior=c;
        rangoMin--;
    }
    printf("El rango de char es: %d hasta %d", rangoMin, rangoMax);
}
