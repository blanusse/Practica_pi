#include <stdio.h>
#include <assert.h>
#include <math.h>
#define ERROR 0.00001

int equal(double a, double b) {
    if (fabs(a-b) < ERROR)
        return 1;
    return 0;
}

double diference (double const a[]) {
    double step = 0;
    for(int i = 1; a[i] != 0; i++){
        (fabs(a[i] - a[i-1]) > step ? (step = fabs(a[i] - a[i-1])): step);
    }
    return step;
}



//Programa para testear la funcion diference
int main() {
    double a[] = {-2, 3.9, 4.2, 1, 0};
    double b[] = {-2, -10, -4, -10, 0};
    double c[] = {-3, 0};
    double d[] = {-10, -9, -7, -6, 0};
    double e[] = {0.2, 0.1, 0.001, 0.00001, 0};
    double f[] = {-1, -1.2, -1.5, 0};

    assert(equal(diference(a), 5.9));
    assert(equal(diference(b), 8));
    assert(equal(diference(c), 0));
    assert(equal(diference(d), 2));
    assert(equal(diference(e), 0.1));
    assert(equal(diference(f), 0.3));
    printf("OK!");


}