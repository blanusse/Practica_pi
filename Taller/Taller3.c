#include <stdio.h>
#include <math.h>

#include "../Lib/getnum.h"
#include <assert.h>

int esPrimo (int num) {
    int divisores = 0;
    if (num<0)
        num = -num;
    for(int div = sqrt(num); div > 1; div--) {
        if (num%div == 0)
            divisores++;
    }
    if(divisores != 0 || num == 0 || num == 1 || num == -1)
        return 0;
    return 1;
}
void nPrimos (int n) {
    for(int i=2; n > 0; i++) {
        if(esPrimo(i)==1) {
            printf("%d) %d \n",n ,  i);
            n--;
        }
    }
}



int sumaDivisores(int a) {
    int sumaA=0;
    for (int i=(a/2); i>0; i--) {
        if ((a%i)==0)
            sumaA+=i;
    }
    return sumaA;
}
int numerosAmigos (int a, int b) {
    return (sumaDivisores(a) == b && sumaDivisores(b) == a);
}




int
main(void) {
    assert(!esPrimo(0)); // 0 no es primo (no es natural)
    assert(!esPrimo(1)); // 1 no es primo
    assert(esPrimo(2)); // 2 es primo
    assert(esPrimo(3));
    assert(!esPrimo(4));
    assert(esPrimo(5));
    assert(!esPrimo(6)); // Equivalente a assert(esPrimo(6) == 0)
    assert(esPrimo(7)); // Equivalente a assert(esPrimo(7) == 1)
    printf("OK!\n");
    return 0;
}