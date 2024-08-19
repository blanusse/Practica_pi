#include <stdio.h>

int main() {
    int c = getchar();
    ((c>=65 && c<=90)||(c>=97 && c<=122))? (printf("%c es una letra", c)): printf("%c no es una letra", c);
}