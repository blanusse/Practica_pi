#include <stdio.h>
/*int main(void) {
    int contador=0;
    for(int c=getchar(); c!='\n';c=getchar()) {
        if(c=='5')
            ++contador;
    }
    printf("%d veces aparecio el cinco", contador);
}*/

int main(void) {
    int contadorCinco=0, contadorEntero=0, contadorDecimal=0;
    for (int c=getchar(); c!=EOF ;c=getchar()) {
        if(c=='.' || c==',')
            contadorEntero=contadorCinco;
        else {
            if (c=='5')
                ++contadorCinco;
        }
    }
    contadorDecimal=contadorCinco;
    printf("Habia %d cincos en la parte entera y %d cincos en la parte decimal", contadorEntero, contadorDecimal);
}