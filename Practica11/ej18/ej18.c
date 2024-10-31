#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *v = calloc(1, sizeof(char));
    int tamV = strlen(v);
    char *a = "Hola";
    int tamA = strlen(a);
    char *b = " ";
    int tamB = strlen(b);
    char *c = "Riquelme";
    int tamC = strlen(c);


    v = realloc(v, sizeof(char)*(tamV+tamA+1));
    strcat(v, a);
    tamV +=tamA;

    v = realloc(v, sizeof(char)*(tamV+tamB+1));
    strcat(v, b);
    tamV +=tamB;


    v = realloc(v, sizeof(char)*(tamV+tamC+1));
    strcat(v, c);





    printf("%s\n", v);
    free(v);
    return 0;
}
