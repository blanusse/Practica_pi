#include <stdio.h>
#include "../Lib/getnum.h"
int
main() {
    float v = getfloat("Ingrese una velocidad: ");
    v = v*3.6;
    printf("Su velocidad es: %.2f km/h", v);
}