#include <stdio.h>
#include <assert.h>
#include <math.h>


int busquedaBinaria(int datos[], int dim, int num) {
    if(dim == 0)
        return 0;
    if(*datos == num)
        return 1;
    if(dim == 1)
        return 0;
    int proxDim = ceil((double)dim/2);
    if(*(datos+ dim/2) > num) {
        return busquedaBinaria(datos, proxDim, num);
    }
    if(*(datos+ dim/2) < num)
        return busquedaBinaria(datos+ dim/2, proxDim, num);
    return 1;
}


int main(void) {

    int v[] = {-10, -5, 0, 5, 10, 15, 20, 25, 30, 35, 40, 45};

    assert(busquedaBinaria(v, 0, -10)==0);
    assert(busquedaBinaria(v, 1, -10)==1);
    assert(busquedaBinaria(v, 2, -10)==1);
    assert(busquedaBinaria(v, 2, -5)==1);
    assert(busquedaBinaria(v, 2, 0)==0);

    assert(busquedaBinaria(v+1, 2, -10)==0);
    assert(busquedaBinaria(v+1, 2, -5)==1);
    assert(busquedaBinaria(v+1, 2, 0)==1);

    for(int i=0; i < 12; i++)
        assert(busquedaBinaria(v, 12, v[i])==1);

    for(int i=0; i < 11; i++)
        assert(busquedaBinaria(v, 11, v[i])==1);


    printf ("OK!\n");
    return 0;
}