#include <stdio.h>

#include "../Lib/getnum.h"

int menuOpciones (void);
//Despliega un menu de opciones

int toUp (unsigned char);
//recibe un valor de una minuscula en ASCII y lo pasa al valor de la mayuscula en ASCII

int toLow (unsigned char);
//recibe un valor de una mayuscula en ASCII y lo pasa al valor de la minuscula en ASCII

int nextChar (unsigned char);
//recibe un valor ASCII de algun caracter y devuelve el valor ASCII del caracter siguiente

int nextLetter(unsigned char);
//recibe un valor ASCII de una letra y avanza a la siguiente letra



int main() {
    unsigned char c = getchar();
    int opcion = menuOpciones();
    switch (opcion) {
        case 1:
            printf("%c", toUp(c));
            break;
        case 2:
            printf("%c", toLow(c));
            break;
        case 3:
            printf("%c", nextChar(c));
            break;
        case 4:
            printf("%c", nextLetter(c));
    }
}

int toUp (unsigned char a) {
    if (a>='a' && a<='z')
        return (a + 'A' - 'a');
    else return a;
}
int toLow (unsigned char a) {
    if (a>='A' && a<='Z')
        return (a + 'a' - 'A');
    else return a;
}
int nextChar (unsigned char a) {
    return a+1;
}

int nextLetter (unsigned char a) {
    if ((a == 'z') || (a == 'Z'))
        return a - 'Z' + 'A';
    else return a+1;
}

int menuOpciones(void) {
    int opcion = getint("1) Convertir de mayuscula a minuscula \n2) Convertir de minusucla a mayuscula\n"
                     "3) Siguiente caracter\n4) Siguiente caracter circular\n");
    return opcion;
}
