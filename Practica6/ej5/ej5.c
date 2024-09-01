#include <stdio.h>
#include <assert.h>
#define INICIALIZADOR 12341234

int eliminaRepOrden (const int v[], int dim, int r[]) {
    int c=0, anterior = INICIALIZADOR;
    for(int i = 0; i<dim; i++) {
        if(v[i] != anterior) {
            r[c] = v[i];
            c++;
        }
        anterior = v[i];
    }
    return c;
}




int main(void) {
    int v[] = { -3, -3, -1, 0, 1, 2, 2, 2, 3, 3, 3};
    int res[20];
    int dimRes;

    dimRes = eliminaRepOrden(v, 0, res);
    assert(dimRes==0);

    dimRes = eliminaRepOrden(v, 1, res);
    assert(dimRes==1);
    assert(res[0]==-3);

    dimRes = eliminaRepOrden(v, 2, res);
    assert(dimRes==1);
    assert(res[0]==-3);

    dimRes = eliminaRepOrden(v, 11, res);
    assert(dimRes==6);
    assert(res[0]==-3);
    assert(res[1]==-1);
    assert(res[2]==0);
    assert(res[3]==1);
    assert(res[4]==2);
    assert(res[5]==3);


    int n=80000;
    int v2[n];
    int res2[n];
    for (int i=0; i < n; i++)
        v2[i] = 100;
    dimRes = eliminaRepOrden(v2, n, res2);
    assert(dimRes==1);
    assert(res2[0]==100);

    for (int i=0; i < n; i++)
        v2[i] =i;
    dimRes = eliminaRepOrden(v2, n, res2);
    assert(dimRes==n);
    for (int i=0; i < n; i++)
        assert(res2[i]==i);

    puts("OK!");
    return 0;
}