#include <stdio.h>
#include "../Lib/getnum.h"

int main() {
    int num1 = getint("Ingresar un entero: ");
    int num2= getint("Ingresar otro entero: ");
    int resto = num2%num1;
    resto==0 ? printf("%d es multiplo de %d", num2, num1): printf("%d no es multiplo de %d", num2, num1);
}
