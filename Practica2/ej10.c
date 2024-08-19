#include <stdio.h>
#include "../Lib/getnum.h"

main() {
    int t = getint("Ingrese un tiempo: ");
    printf("Son %d segundos\n", t);
    t = t/60;
    printf("Son %d minutos\n", t);
    t=t/60;
    printf("Son %d horas\n", t);
}