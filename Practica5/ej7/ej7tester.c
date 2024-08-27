#include <assert.h>
#include <stdio.h>
#include "ej7.h"


int main() {
    double x = getint("Ingrese un numero: ");
    assert(equals(ex(x), exp(x))); // significa que el error entre el valor calculado y el real es minimo o nulo
    printf("OK!");
    printf("%f\n%f", ex(x), exp(x));
}
