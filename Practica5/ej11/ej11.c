#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int esVocal(int a) {
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')
        return 1;
    return 0;
}

int main() {
    int a = getchar(), b = getchar(), c =getchar();
    if(isupper(a) && !esVocal(a))
        printf("El caracter %c es una consonante mayucula\n", a);
    else if (islower(a) && !esVocal(a))
        printf("El caracter %c es una consonante minuscula\n", a);
    else if (esVocal(a))
        printf("El caracter %c es una vocal\n", a);
    else printf("El caracter %c no es una letra\n", a);

    if (b%2 == 0)
        printf("El valor ASCII de %c es par\n", b);
    if (isdigit(b) && b%2 == 0)
        printf("El caracter %c representa un digito par\n", b);
    if (esVocal(c) || isupper(c))
        printf("El caracter %c es una vocal o es mayuscula\n", c);
    if (isalpha(c) && !esVocal(c))
        printf("El catacter %c no es una vocal pero es letra\n", c);
    return 0;

}