#include <ctype.h>
#include <stdio.h>

#include "../../Lib/getnum.h"

int main() {
    int n, c=0;
    n = getint("");
    //Al salir del ciclo debe ser un numero par mayor que cero
    while (n%2 != && n<0);


    //Este ciclo debe incluir la lectura de caracteres y
    //debe ejecutarse mientras no sea fin de archivo y los caracteres sean digitos o minusculas

    while((islower(c) || isdigit(c)) && c != EOF)
        c = getchar();
        putchar(c);

}
