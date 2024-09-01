#include <stdio.h>
#define END -1

void unirArreglos (int a[], int b[], int r[]) {
    int c=0;
    for(int i=0, k=0; (a[i] != END || b[k] != END); c++) {
        if(a[i] == END) {
            r[c] = b[k];
            k++;
        }
        else if(b[k] == END){
            r[c] = a[i];
            i++;
        }
        else if (b[k]<a[i]) {
            r[c] = b[k];
            k++;
        }
        else if (a[i]<b[k]) {
            r[c] = a[i];
            i++;
        }
        else if (a[i]==b[k]) {
            r[c] = a[i];
            i++;
            k++;
        }
    }
    r[c] = END;
}

void mergeArray(int a[], int b[], int r[]) {
    unirArreglos(a, b, r);
    int anterior;
    for(int i=0; r[i] != END; i++) {
        for(int j = 1; r[i] == anterior; j++) {
            r[i] = r[i+j];
            }
        anterior = r[i];
    }
}


int main() {
    int v1[] = {1,1,5, -1};
    int v2[] = {3, 3, 4,4, 4, 6, -1};
    int r[30] = {0};
    unirArreglos(v1, v2, r);
    for(int i =0; r[i] != END; i++)
        printf("%d", r[i]);
    printf("\n");
    mergeArray(v1, v2, r);
    for(int i =0; r[i] != END; i++)
        printf("%d", r[i]);
}