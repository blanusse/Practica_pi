#include <stdio.h>
#include "../Lib/getnum.h"
int main() {
    int num = getint("Ingrese un numero: "), invertido = 0;
    int original = num;
    for(; num > 0; num /= 10) {
        invertido = invertido*10 + num % 10; /*Se fija el digito mas a la derecha del numero y lo pone primero*/
    }
    if (original == invertido)
        printf("%d es capicua", original);
    else printf("%d no es capicua", original);
}
