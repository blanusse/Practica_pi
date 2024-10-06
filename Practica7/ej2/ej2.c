#include <math.h>
#include <stdio.h>

#include "../../lib/getnum.h"

int baseAnum(int base1, int num) {
    int count = 0;
    for(int i=0; num>0; i++) {
        count += (num % 10) * pow(base1, i);
        num/=10;
    }
    return count;
}



void cambioDeBase(int *base1, int *num, int *base2) {
    int numReal = baseAnum(*base1, *num);
    *num = 0;
    for(int i=0; numReal>0; i++) {
        *num += numReal % *base2;
        *num *= 10;
        numReal /= *base2;
    }
}


int main() {
     int base1, base2;
     // printf("Ingrese las bases: ");
     // scanf("< %d > %d", &base1, &base2);
     // if(base1 < 2 || base1 > 10 || base2 < 2 || base2 > 10) {
     //     printf("Las bases deben estar entre 2 y 10");
     //     return 0;
     // }
     // int ans = getint("Ingrese el numero: ");
     // cambioDeBase(&base1, &ans, &base2);
     // printf("El numero nuevo es: %d", ans);
    int a = 2;
    int b = 1101;
    int c = 9;
    cambioDeBase(&a, &b, &c);
    printf("%d", b);

}
