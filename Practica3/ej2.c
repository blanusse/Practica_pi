#include <stdio.h>
int main(void) {
    int a=getchar();
    int b=getchar();
    if (a>b)
        printf("%c es mayor que %c", a, b);
    else if (a<b)
        printf("%c es menor que %c", a, b);
    else
        printf("%c es igual que %c", a, b);
}