#include <ctype.h>
#include <stdio.h>
#include <string.h>


void palotes(unsigned int cant) {
    if(cant == 0)
        return;
    printf("|\t");
    palotes(cant-1);
}


int longitud(char palabra[]) {
    int aux=0;

    if(*palabra == '\0') {
        return 0;
    }
    if((*palabra) >= ' ' && (*palabra) <= '~') {
        aux = 1;
    }

    return aux + longitud(palabra+1);
}

char * buscaCaracter(char palabra[], char letra) {
    if(*palabra == letra)
        return palabra;
    return buscaCaracter(++palabra, letra);

}


int main() {
    palotes(4);
    char palabra[] = "mdfnkjdsf A<d1`2/.24,2 1`";
    printf("\n%d", longitud(palabra));
    printf("\n%d", strlen(palabra));
    printf("\n%s", buscaCaracter(palabra, 'f'));
 }
