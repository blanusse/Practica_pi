#include <stdio.h>
#include <stdlib.h>
#define FUNCION(x)   (x)-52
#define EPSILON     0.000002
#define BLOCK 10

typedef struct {
    double punto1;
    double punto2;
}particion;

struct respuesta {
    int dim;
    particion *raices;
};

struct respuesta buscaRaices(particion intervalo) {
    struct respuesta ans;
    ans.raices = NULL;
    int count=0;
    double salto = (intervalo.punto2 - intervalo.punto1+1)/1000;
    for(double i=intervalo.punto1; i<intervalo.punto2; i+=salto) {
        if(abs(FUNCION(i)) < EPSILON) { // Si la funcion da cero
            if(count%BLOCK == 0) {
                ans.raices = realloc(ans.raices, (count+BLOCK)*sizeof(particion));
            }
            ans.raices[count].punto1 = i-salto;
            while (abs(FUNCION(i)) < EPSILON)
                i+=salto;
            ans.raices[count].punto2 = i;
            count++;
        }
        if((FUNCION(i) > 0 && FUNCION(i)+salto < 0) || (FUNCION(i) < 0 && FUNCION(i+salto) >0)) { //Si cambia de signo
            if(count%BLOCK == 0) {
                ans.raices = realloc(ans.raices, (count+BLOCK)*sizeof(particion));
            }
            ans.raices[count].punto1 = i;
            ans.raices[count].punto1 = i+salto;
            i+=salto;
            count++;
        }
    }
    ans.dim = count;
    return ans;
}



int main() {
    particion intervalo = {1, 50000};
    struct respuesta ans = buscaRaices(intervalo);
    printf("Dimension: %d\n", ans.dim);
    for(int i=0; i<ans.dim; i++) {
        printf("%d\t%d\n", ans.raices[i].punto1, ans.raices[i].punto2);
    }
    free(ans.raices);
}