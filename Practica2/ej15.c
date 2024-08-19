#include <stdio.h>
#include "../Lib/getnum.h"

int main() {
    int c = getchar();
    (c>=65 && c<=90) ? printf("%c", c) : printf("%c",(c-32));
}
