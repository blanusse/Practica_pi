#include <stdio.h>
#include "complejosADT.h"
#include <assert.h>
#include <stdlib.h>

#define EPS 0.01


int main(void) {
    complejosADT comp1 = newComplex( 1, 2 ); // comp1 = 1 + 2i
    complejosADT comp2 = newComplex( 2, -3 ); // comp2 = 2 - 3i
    complejosADT ans;

    ans = sumComp( comp1, comp2 );
    assert( getReal(ans) - 3 < EPS && getImaginary(ans) + 1 < EPS );
    free( ans );

    ans = restaComp( comp1, comp2 );
    assert( getReal(ans) - 1 < EPS && getImaginary(ans) - 5 < EPS );
    freeComp( ans );

    ans = multComp( comp1, comp2 );
    assert( getReal(ans) - 8 < EPS && getImaginary(ans) - 1 < EPS );
    freeComp( ans );

    ans = divideComp( comp1, comp2 );
    assert( getReal(ans) + 0.31 < EPS && getImaginary(ans) - 0.54 < EPS );
    freeComp( ans );

    ans = conjComp( comp1 );
    assert( getReal(ans) - 1 < EPS && getImaginary(ans) + 2 < EPS );

    freeComp( comp1 );
    freeComp( comp2 );
    freeComp( ans );

    printf("OK!\n");
}
