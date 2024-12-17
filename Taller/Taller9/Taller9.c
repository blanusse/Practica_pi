#include <math.h>
#include <stdio.h>
#include <assert.h>

int esPotenciaDe3_2(double n) {
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return esPotenciaDe3_2(n/3);
}


int esPotenciaDe3(int n) {
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return (n%3 == 0) && (esPotenciaDe3(n/3));
}

// int main() {
//     printf("%d\n", esPotenciaDe3(0));
//
//     printf("%d\n", esPotenciaDe3(3));
//     printf("%d\n", esPotenciaDe3(12));
//     printf("%d\n", esPotenciaDe3(15));
//     printf("%d\n", esPotenciaDe3(27));
//     printf("%d\n", esPotenciaDe3(81));
//     printf("%d\n", esPotenciaDe3(99));
// }


//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------


int igualesRet(int a[], int b[]) {

    if(*a == -1 || *b == -1) {
        if(*a == -1 && *b == -1)
            return 1;
        return 0;
    }
    return (*a == *b) && igualesRet(++a, ++b);
}

void igualesVoid(int a[], int b[], int *res) {
    *res = igualesRet(a, b);
}


//
// int main() {
//     int a[] = {1, 2, 3, 4, 5, -1};
//     int b[] = {1, 3, -1};
//     int c[] = {1, 2, 3, 4, 5, -1};
//     int d[] = {1, 2, 3, 4, 5, -1};
//     printf("%d\n%d", igualesRet(a, b), igualesRet(c, d));
// }


//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------


void recMinMax(int a[], int dim, int *min, int *max){
    if(dim == 0) {
        *max = 0;
        *min = 0;
        return;
    }
    if(dim == 1 && *a >0) {
        *min = *a;
        *max = *a;
        return;
    }
    if(*a < 1) {
        *max = -1;
        *min = -1;
        return;
    }
    recMinMax(++a, dim-1, min, max);
    if(*min != -1 && *a <*min) {
        *min = *a;
    }
    if(*min != -1 && *a >*max) {
        *max = *a;
    }
}



int
main(void) {
    int v[] = {3, 1, 5, 2, 6, 99,-1, 2};
    int min, max;
    recMinMax(v, 6, &min, &max);
    printf("%d,%d\n"
    , min, max); // 1,99
    recMinMax(v, 8, &min, &max);
    printf("%d,%d\n"
    , min, max); // -1,-1
    recMinMax(v, 0, &min, &max);
    printf("%d,%d\n"
    , min, max); // 0,0
}

//
// int
// main(void) {
//     int v[] = {3, 1, 5, 2, 6, 99, -3, 2};
//     int min, max;
//     recMinMax(v, 0, &min, &max);
//     assert(min == 0 && max == 0);
//     recMinMax(v, 1, &min, &max);
//     assert(min == 3 && max == 3);
//     recMinMax(v, 2, &min, &max);
//     assert(min == 1 && max == 3);
//     recMinMax(v, 3, &min, &max);
//     assert(min == 1 && max == 5);
//     recMinMax(v, 6, &min, &max);
//     assert(min == 1 && max == 99);
//     recMinMax(v, 8, &min, &max);
//     assert(min == -1 && max == -1);
//     printf("OK!\n");
//     return 0;
// }