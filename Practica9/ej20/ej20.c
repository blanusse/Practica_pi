#include <stdio.h>


int main() {
    for(int i = 1; i!=10; i++) {
    printf("add_executable(Prac10.%d Practica10/ej%d/ej%d.c Lib/getnum.c Lib/random.c)\n", i, i, i);
    }
    return 0;
}