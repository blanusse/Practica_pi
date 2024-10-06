#include <stdio.h>
#include <stdlib.h>
#define BLOCK   5


int  * orden(int a[], int dimA, int b[], int dimB, int *dimRes) {
    int *res = NULL;
    int i, j;
    *dimRes = 0;
    for(i=0, j=0; i<dimA && j < dimB; ) {


        if(a[i] < b[j])
            i++;
        else if(a[i] > b[j]) {
            j++;
        }
        else {
            if(*dimRes % BLOCK == 0)
                res = realloc(res, (i+BLOCK) * sizeof(int));
            res[(*dimRes)++] = a[i++];
            j++;
        }
    }
    res = realloc(res, *dimRes * sizeof(int));
    return res;
}

int main() {
    int a[] = {1, 2, 5, 6, 7};
    int b[] = {2, 3, 4, 5, 7, 9, 10};
    int dimA = sizeof(a)/sizeof(a[0]);
    int dimB = sizeof(b)/sizeof(b[0]);
    int dimRes;
    int *res = orden(a, dimA, b, dimB, &dimRes);
    for(int i=0; i<dimRes; i++) {
        printf("%d ", res[i]);
    }
    free(res);
}