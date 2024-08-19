#include <stdio.h>
#include "../Lib/getnum.h"

int main() {
    int a = getchar();
    int b = getchar();
    (a==b)? printf("Son iguales") : ((a<b)? printf("%c es menor que %c", a, b): printf("%c es mayor que %c", a, b));

}
