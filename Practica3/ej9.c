#include <stdio.h>
/*
int main(void) {
    int espacios=0, tabs=0, lineas=0;
    for(int c=getchar();c != 'E' && c != EOF; c=getchar()) {
        if (c == ' ')
            espacios++;
        else if (c == '\n')
            lineas++;
        else if (c == '\t')
            tabs++;
    }
    printf("Habia %d espacios, %d tabs y %d lineas", espacios, tabs, espacios);
}*/
/*Uso la tecla E para terminar con la entrada estandar*/


int main() {
    for(int c=getchar(); c != '\n' && c != EOF; c=getchar()) {
        if (c == ' ')
            printf("\n");
        else
            printf("%c", c);
    }
}