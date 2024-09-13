#include <stdio.h>
#include <assert.h>

void secuenciaAsc(const int v[], int dim, int *start, int *length) {

    if (dim == 0) {
        *start = NULL;
        *length = NULL;
    }
    else {
        *start = 0;
        *length = 1;
        int count = 0, prevCount = 0, pos =0;
        for(int i=0; i<dim; i++) {
            prevCount = count;
            count = 1;
            pos = i;
            for(; i<dim-1 && v[i]<v[i+1]; i++) {
                count++;
            }
            if (count > prevCount) {
                *length = count;
                *start = pos;
            }
        }
    }


}


int main(void) {
    // Para el vector {1, 1, 3, 4, 4, 7, 10, 9, 11} el comienzo es 1 y su longitud es 3
    int v1[] = {1, 1, 3, 4, 4, 7, 10, 9, 11};
    int dim1 = sizeof(v1) / sizeof(v1[0]);
    int com1, lon1;
    secuenciaAsc(v1, dim1, &com1, &lon1);
    assert(com1 == 1 && lon1 == 3);

    // Para el vector vacío comienzo y longitud son 0 (cero)
    secuenciaAsc(v1, 0, &com1, &lon1);
    assert(com1 == 0 && lon1 == 0);

    // Para los vectores {3}, {2, 2, 2} y  {3, 2, 1, 0, -1}  el comienzo es 0 y la longitud es 1
    int v2[] = {3};
    int com2, lon2;
    secuenciaAsc(v2, 1, &com2, &lon2);
    assert(com2 == 0 && lon2 == 1);
    int v3[] = {2, 2, 2};
    int com3, lon3;
    secuenciaAsc(v3, 3, &com3, &lon3);
    assert(com3 == 0 && lon3 == 1);
    int v4[] = {3, 2, 1, 0, -1};
    int com4, lon4;
    secuenciaAsc(v4, 5, &com4, &lon4);
    assert(com4 == 0 && lon4 == 1);

    // Para el vector {1, 2, 3, 4, 5, 7, 10, 90, 111}  el comienzo es 0 y la longitud 9
    int v5[] = {1, 2, 3, 4, 5, 7, 10, 90, 111};
    int dim5 = sizeof(v5) / sizeof(v5[0]);
    int com5, lon5;
    secuenciaAsc(v5, dim5, &com5, &lon5);
    assert(com5 == 0 && lon5 == 9);

    // Para el vector {1, 2, 1, 4, 5, 7, 1, 90, 111}  el comienzo es 2 y la longitud 4
    int v6[] = {1, 2, 1, 4, 5, 7, 1, 90, 111};
    int dim6 = sizeof(v6) / sizeof(v6[0]);
    int com6, lon6;
    secuenciaAsc(v6, dim6, &com6, &lon6);
    assert(com6 == 2 && lon6 == 4);

    puts("OK!");
    return 0;
}