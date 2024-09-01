#include <math.h>
#include <stdio.h>
#include <assert.h>
#define NUM 0x0F

double calcProm (unsigned char a[], int n) {
    double acumulador =0, contador = n;
    for (int i=0; contador>0; i++) {
        acumulador += (a[i]>>4)&NUM;
        contador--;
        if(contador>0) {
            acumulador += a[i]&NUM;
            contador--;
        }
    }
    return acumulador/n;
}

double sumDesviacion (unsigned char a[], int n) {
    double media = calcProm(a, n);
    double acum = 0, contador = n;
    for (int i=0; contador > 0; i++) {
        acum += pow((a[i]>>4&NUM)-media, 2);
        contador--;
        if (contador >0) {
            acum += pow((a[i]&NUM)-media, 2);
            contador--;
        }
    }
    return acum;
}


double desv (unsigned char v[], int n){
    if (n==0)
        return 0;
    double suma = sumDesviacion(v, n);
    return sqrt(suma/n);

}

int main(void) {
    double d;
    unsigned char arreglo2[] = { 0x33, 0x33, 0x33, 0x33, 0x33 };
    for(int i=0; i <= 10; i++)
        assert(desv(arreglo2, i)==0);


    unsigned char arreglo[] = { 0x37, 0xF2, 0x03, 0x4A, 0xFF };
    assert(desv(arreglo, 1)==0);
    assert(desv(arreglo, 2)==2.0);

    assert(desv(arreglo, 3) > 4.98 && desv(arreglo, 3) < 4.99);

    assert(desv(arreglo, 10) > 5.6071 && desv(arreglo, 3) < 5.6072);

    puts("OK!");
}



/*
int main() {
    unsigned char v1[] = {0x33, 0x33, 0x33, 0x33, 0x33};
    int dim = (sizeof(v1)/sizeof(v1[0]))*2;
    printf("%f\n", calcProm(v1, 3));
    printf("%f\n", sumDesviacion(v1, 3));
    printf("%f", desv(v1, 3));

}
*/
