#include <stdio.h>
#include <ctype.h>

int esVocal(char letra) {
    letra = toupper(letra);
    if(letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U')
        return 1;
    return 0;
}

int cantVoc(char frase[]) {
    if(*frase == '\0')
        return 0;
    return esVocal(*frase) + cantVoc(frase+1);
}

int main() {
    char m[] = "Hola como te va";
    printf("%d", cantVoc(m));
}