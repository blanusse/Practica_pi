#include <stdio.h>
#include <limits.h>

int
main(void) {
    int c = INT_MAX;
    int d;
    d = c + c;
    int e = c + 1;

    printf("c=%d   d=%d   e=%d\n", c, d, e);
    return 0;
}