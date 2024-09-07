#include <stdio.h>
#include <assert.h>
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



void check(const int v1[], const int v2[]) {
    int i;
    for(i=0; v1[i] != -1; i++)
        assert(v1[i]==v2[i]);
    assert(v1[i]==-1);
    assert(v2[i]==-1);
}

int main(void) {
    int v1[] = { 1, 5, 15, 30, 35, 45, 55, -1};
    int v2[] = {-1};
    int v3[] = { 1, -1};
    int v4[] = { 2, 3, 15, 16, 33, 35, 45, 65, -1};
    int dimRes;
    int res[30];

    unirArreglos(v1, v2, res);
    check(v1, res);

    unirArreglos(v2, v2, res);
    check(v2, res);

    unirArreglos(v1, v1, res);
    check(v1, res);

    unirArreglos(v1, v3, res);
    check(v1, res);

    int expected[] = {1, 2, 3, 5, 15, 16, 30, 33, 35, 45, 55, 65, -1};
    unirArreglos(v1, v4, res);
    check(expected, res);

    printf("OK!\n");
    return 0;
}