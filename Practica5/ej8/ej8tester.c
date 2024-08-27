#include <assert.h>
#include <stdio.h>
#include "ej8.h"
#include "../Lib/getnum.h"

/*
//PUNTO A//
int main() {
    double x = 1.121233;
    assert(equal(redondeo(x, 0), 1));
    assert(equal(redondeo(x, 1), 1.1));
    assert(equal(redondeo(x, 2), 1.12));
    assert(equal(redondeo(x, 3), 1.121));
    assert(equal(redondeo(x, 4), 1.1212));
    assert(equal(redondeo(x, 5), 1.12123));
    assert(equal(redondeo(x, 6), 1.121233));

    x = 9.919992;

    assert(equal(redondeo(x, 0), 10));
    assert(equal(redondeo(x, 1), 9.9));
    assert(equal(redondeo(x, 2), 9.92));
    assert(equal(redondeo(x, 3), 9.920));
    assert(equal(redondeo(x, 4), 9.9200));
    assert(equal(redondeo(x, 5), 9.91999));
    assert(equal(redondeo(x, 6), 9.919992));

    puts("OK!");
    return 0;
}
*/
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

//PUNTO B//

int main() {
    double num = getfloat("Ingrese un numero real: ");
    int opcion = menuOpciones();
    switch (opcion) {
        case 1:
            printf("%f", redondeo(num, 0));
            break;
        case 2:
            printf("%f", redondeo(num, 1));
            break;
        case 3:
            printf("%f", redondeo(num, 2));
            break;
        case 4:
            printf("%f", redondeo(num, 3));
    }
    return 0;
}