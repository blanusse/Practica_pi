#include <stdio.h>



int elimina(int a[], int dimA, int b[], int dimB) {
    if (dimA > 0 && dimB > 0) {
        int dimC = 0;
        int i = 0, j=0, k=0;
        for(; i<dimA && k<dimB; ) {
            if(a[i] > b[k])
                k++;
            else if(a[i]<b[k]) {
                a[j] = a[i];
                j++;
                i++;
                dimC++;
            }
            else if(a[i]==b[k]) {
                i++;
            }
        }
        while(i<dimA) {
            a[j]=a[i];
            i++;
            j++;
            dimC++;
        }
        return dimC;
    }
     return 0;
}

int main() {
    int a[] = {1, 2, 3, 4 ,5, 6};
    int b[] = {2, 3, 4};
    int dimA = sizeof(a)/sizeof(a[0]);
    int dimB = sizeof(b)/sizeof(b[0]);
    int dimC = elimina(a, dimA, b, dimB);
    for(int i=0; i<dimC; i++) {
        printf("%d\t", a[i]);
    }

}

