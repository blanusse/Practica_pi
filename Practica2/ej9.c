#include <stdio.h>
#include "../Lib/getnum.h"

main(){
    int n=getint("Ingrese un numero entero: ");
    n>>=1;
    printf("%d", n);

}
