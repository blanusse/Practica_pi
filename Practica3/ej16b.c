#include <stdio.h>
#include "../Lib/getnum.h"


int main() {
    int num = getint("Ingrese un numero: "), digito=0;
    for(int i=32768; i > 0; i/=2) {
        if (i<=num) {
            printf("1");
            num=num-i;
        }
        else printf("0");
        digito++;
        if(digito==4) {
            printf(" ");
            digito=0;
        }

    }
}


