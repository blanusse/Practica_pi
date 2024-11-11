#include <stdio.h>
#include <assert.h>
#include "boolMatADT.h"

int
main(void) {
    boolMatADT m = newBoolMat();

    assert(getValue(m, 0, 1) == false);
    assert(getValue(m, 9870, 154632) == false);
    assert(getValue(m, 74645212, 123255) == false);

    setTrue(m, 10, 15);
    setTrue(m, 10, 1000);

    assert(getValue(m, 10, 15) == true);
    assert(getValue(m, 15, 10) == false);
    assert(getValue(m, 10, 1000) == true);

    setFalse(m, 10, 1000); // borro la celda 10;1000
    assert(getValue(m, 10, 1000) == false);


    setTrue(m, 74645212, 123255);

    assert(getValue(m, 10, 15) == true);
    assert(getValue(m, 10, 1000) == false);
    assert(getValue(m, 9870, 154632) == false);
    assert(getValue(m, 74645212, 123255) == true);

    freeBoolMat(m);

    puts("OK!");
    return 0;
}