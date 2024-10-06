#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#define BLOCK   10
#define NOTA_MINIMA     4


typedef char *TAlumnos[];

char ** aprobados(TAlumnos alumnos, const int notas[] ) {
    char **alumnosAprobados = NULL;
    int cantAprob = 0;
    for(int i=0; alumnos[i][0] != '\0' ; i++) {
        if(notas[i] >= NOTA_MINIMA) {
            if(i%BLOCK == 0)
                alumnosAprobados = realloc(alumnosAprobados, (i+BLOCK) * sizeof(char *));
            alumnosAprobados[cantAprob] = malloc(strlen(alumnos[i]) + 1);
            strcpy(alumnosAprobados[cantAprob++], alumnos[i]);
        }

    }
    alumnosAprobados = realloc(alumnosAprobados, (cantAprob+1)*sizeof(char*));
    alumnosAprobados[cantAprob] = "";
    return alumnosAprobados;
}

void liberarAprob(TAlumnos alumnos) {
    for(int i=0; *alumnos[i]; i++) {
        free(alumnos[i]);
    }
}

int main() {
    char *alumnos[] = {"ana", "pedro", "juan", "julia", "beltran", ""};
    int notas[] = {4, 2, 1, 9, 3};
    char **alumAprobados;
    alumAprobados = aprobados(alumnos, notas);
    for(int i=0; alumAprobados[i][0] != '\0'; i++) {
        printf("%s\n", alumAprobados[i]);
    }
    liberar(alumAprobados);
    free(alumAprobados);
}