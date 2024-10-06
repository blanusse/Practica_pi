#include <stdio.h>

int main() {
    for(int i=1; i<21; i++) {
        printf("add_executable(TP07_ej%d TP07/ej%d/ej.c Lib/getnum.c Lib/random.c)\n", i, i);
    }
}