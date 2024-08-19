#include <stdio.h>
#include "../Lib/getnum.h"
int main(void) {
    int num=getint("Ingrese un numero"), total=num;
    if(num<0)
        printf("Numero invalido, ingresar un numero mayor o igual a cero");
    else {
        for (--num;num>0;num--) {
            total=total*num;
        }
        printf("%d", total);
    }
}
