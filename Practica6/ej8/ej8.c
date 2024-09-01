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
int seRepite (int a, int posicion, int v[]) {
    int contador=1;
    for(int k = 0; k<posicion; k++) {
        if (a == v[k])
            contador++;
    }
    return (contador!=1);
}




int mergeArray(int a[], int b[], int r[]) {
    int ar[30];
    unirArreglos(a, b, ar);
    int c=0;
    for(int i=0; ar[i] != END; i++) {
        if (!seRepite(ar[i], i, ar)) {
            r[c] = ar[i];
            c++;
        }
    }
    r[c] = END;

}

/*
int main() {
    int v1[] = {1, 2, 3, 4,4, 5 ,5, 7, -1};
    int v2[] = {3, 4, 4, 5, -1};
    int r[30];
    mergeArray(v1, v2, r);
    for(int i=0; r[i] != -1; i++) {
        printf("%d", r[i]);
    }
}*/




void check(const int v1[], const int v2[]) {
    int i;
    for(i=0; v1[i] != -1; i++)
        assert(v1[i]==v2[i]);
    assert(v1[i]==-1);
    assert(v2[i]==-1);
}

int main(void) {
    int v1[] = { 1, 5, 15, 15, 30, 35, 35, 35, 35, 35, 45, 55, -1};
    int v2[] = {-1};
    int v3[] = { 1, 1, 1, 1, 1, 1, -1};
    int v4[] = { 2, 3, 15, 16, 33, 35, 45, 65, -1};

    int res[30];

    int v1_v2[] = {1, 5, 15, 30, 35, 45, 55, -1};
    mergeArray(v1, v2, res);
    check(v1_v2, res);

    mergeArray(v2, v2, res);
    check(v2, res);

    mergeArray(v1, v1, res);
    check(v1_v2, res);

    mergeArray(v1, v3, res);
    check(v1_v2, res);

    int expected[] = {1, 2, 3, 5, 15, 16, 30, 33, 35, 45, 55, 65, -1};
    mergeArray(v1, v4, res);
    check(expected, res);

    puts("OK!");
    return 0;
}