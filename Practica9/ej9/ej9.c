#include <stdio.h>
#include <assert.h>
#include <math.h>

#define EPSILON 0.01




double raizNR(double valorAnterior, int iter, double x)
{
    if(iter==0)
        return valorAnterior;

    return raizNR((valorAnterior+ x/valorAnterior)/2,iter-1,x);
}


int main(void){

    assert(fabs(raizNR(4, 3, 8)-2.833) <= EPSILON);
    assert(raizNR(0, 0, 0) <= EPSILON);
    assert(raizNR(0, 0, 4) <= EPSILON);

    printf("OK!\n");
}