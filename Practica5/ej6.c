#include <stdio.h>

int menuOpciones(void) {
    int eleccion = 0;
    printf("Elegir una opcion \n 1- Convertir de mayuscula a minuscula\n 2- Convertir de minuscula a mayuscula\n 3- Imprimir el caracter siguiente\n 4- Imprimir la siguiente letra en forma circular\n");
    while (eleccion < '1' || eleccion > '4') {
        printf("Ingrese un numero del 1 al 4: ");
        eleccion = getchar();
    }
    return eleccion - '0';
}

int main() {
    for (int entrada = getchar(); entrada != '\n'; entrada = getchar()) {
        int opcion = menuOpciones();
        if (opcion == 1) {
            printf("%c", entrada - 'A' +'a')
        }
    }
}
