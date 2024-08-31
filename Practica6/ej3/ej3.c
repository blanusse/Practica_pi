#include <stdio.h>
#include <assert.h>
#include <math.h>
#define ERROR 0.00000001

int equal(double a, double b) {
    return (fabs(a-b) <=ERROR) ? 1 : 0;
}

double diference (double const a[]) {
    double diferencia=0;
    for(int i = 1; a[i] != 0; i++){
        ((a[i] - a[i-1]) > diferencia ? (diferencia = a[i] - a[i-1]): diferencia);
    }
    return diferencia;
}


int main() {
    double a[] = {-2, 3.9, 4.2, 1, 0};
    double b[] = {-2, 3.9, 4.2, 1, 0};
    double c[] = {-2, 3.9, 4.2, 1, 0};
    double d[] = {-2, 3.9, 4.2, 1, 0};
    double e[] = {-2, 3.9, 4.2, 1, 0};
    double f[] = {-2, 3.9, 4.2, 1, 0};

    printf("%.3f", diference(a));
    assert(equal(diference(a), 3));
    assert(equal(diference(b), 3));
    assert(equal(diference(c), 3));
    assert(equal(diference(d), 3));
    assert(equal(diference(e), 3));
    assert(equal(diference(f), 3));
}