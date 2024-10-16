#include <stdio.h>
#include <stddef.h>

#define TAM_PALABRA     4


#define OFFS(tipo, campo)

//offsetof(tipo, campo);

//tipo ----> struct
//campo ---> variable dentro de struct

typedef struct{
    int x;
    char hola;
    // double probando;
    char chau[25];
}prueba;



int main() {
    int p, t;
    printf("%d\n", sizeof(prueba));
    // int n = offsetof(prueba, probando);
    // printf("%d" ,n);
for(int i = 1; i!=21; i++) {
printf("add_executable(Prac9.%d Practica9/ej%d/ej%d.c Lib/getnum.c Lib/random.c)\n", i, i, i);
}
return 0;
}
