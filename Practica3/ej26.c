#include <stdio.h>
#include "../Lib/getnum.h"
int main () {
    int suma=0;
    for(int i=getint("Ingresa la base"); i<100;i++) {
        suma+=i;
    }
    printf("La suma es %d", suma);
}
