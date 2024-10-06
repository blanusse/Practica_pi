#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * copiaPrefijo(char *s,  int n) {
    char *res = NULL;
    res = realloc(res, (n+1) *sizeof(char));
    strncpy(res, s, n);
    *(res+n) = 0;
    return res;

}

int main() {
    char *a = "bisabuelo";
    int n = 3;
    char *res;
    res = copiaPrefijo(a, n);
    printf("%s", res);
    free(res);
}