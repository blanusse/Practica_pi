#include <stdio.h>
#include <assert.h>
#include <string.h>
#define MAX_ALUMNOS     10
#define MAX_LARGO   100


void separaCursos( char nombre[][MAX_LARGO], char *curso, char cursoG[][MAX_LARGO], char cursoH[][MAX_LARGO]) {
    int g=0, h=0;
    for(int i=0; strcmp(nombre[i], ""); i++) {
        if(curso[i] == 'G')
            strcpy(cursoG[g++], nombre[i]);
        else
            strcpy(cursoH[h++], nombre[i]);
    }

}


typedef char * TAlumnos[MAX_ALUMNOS][MAX_LARGO];
typedef char *TCurso;

int main(void){

    TAlumnos alumnos={"Juan", "Pedro", "Martin", ""}, cursoG, cursoH;
    char  *curso[] = {'H', 'G', 'H', 0};
    separaCursos(alumnos, curso, cursoG, cursoH);
    assert(!strcmp(cursoG[0], alumnos[1]));
    assert(!strcmp(cursoH[0], alumnos[0]));
    assert(!strcmp(cursoH[1], alumnos[2]));
    assert(!strcmp(cursoG[1], alumnos[3]) && !strcmp(cursoH[2], alumnos[3]));   // Terminan con ""

    strcpy(alumnos[0], "");
    curso[0]=0;  // Depende del tipo de alumnos, esta linea puede ser: "alumnos[0][0]=0; curso[0]=0;"
    separaCursos(alumnos, curso, cursoG, cursoH);
    assert(!strcmp(cursoG[0], alumnos[0]) && !strcmp(cursoH[0], alumnos[0]));

    puts("OK!");
    return 0;
}