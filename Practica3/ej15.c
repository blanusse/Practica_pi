#include <stdio.h>

#include "../Lib/getnum.h"





int main(void) {
    int exponente = 1, total=0;
    for(int num = getint("Ingrese un numero binario: "); num > 0; num /= 10) {
        if((num % 10)== 1) {
            total += exponente;
        }
        exponente *= 2;
    }
    printf("%d", total);
    return 0;
}