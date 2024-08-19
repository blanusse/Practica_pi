#include <stdio.h>

int main(void) {
    int c;  // Variable para almacenar el carácter leído
    int contador_P = 0;  // Contador para las 'P'

    // Leer caracteres hasta el fin de la entrada (EOF)
    while (((c = getchar()) != EOF)&&((c=getchar())!='r')) {
        if (c == 'P') {
            contador_P++;  // Incrementar el contador si el carácter es 'P'
        }
    }

    // Imprimir el número de veces que apareció 'P'
    printf("La letra 'P' apareció %d veces\n", contador_P);

    return 0;
}
