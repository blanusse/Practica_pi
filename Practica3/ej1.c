#include <stdio.h>
int main(void) {
    int c =getchar();
    if (c>=65 && c<=90)
        printf("%c es una letra mayuscula", c);
    else if (c>=97 && c<=122)
        printf("%c es una letra minuscula", c);
    else
        printf("%c no es una letra", c);
}

