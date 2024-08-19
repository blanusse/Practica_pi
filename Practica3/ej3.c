#include <stdio.h>
#include "../Lib/getnum.h"
int main(void) {
    float fijo = 300;
    float cobro;
    float ventas = getint("Ingrese el valor de las ventas");
    if (ventas<1000)
        cobro = fijo;
    else if (ventas<2000)
        cobro = fijo+(ventas*5)/100;
    else if (ventas<4000)
        cobro = fijo+(ventas*7)/100;
    else if (ventas>4000)
        cobro = fijo+(ventas*9)/100;
    printf("Cobrarias %.2f", cobro);
}