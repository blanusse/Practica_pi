#include <stdio.h>
#include <assert.h>
#include <string.h>

char *strrchrRec(char *text, char letter, unsigned int dim) {
    if(dim == 0)
        return NULL;

    if(text[dim-1] == letter) {
        return (text+dim-1);

    }
    return strrchrRec(text, letter, dim-1);
}


char *wrapperStrrchrRec(char *text, char letter) {
    int dim = strlen(text);
    return  strrchrRec(text, letter, dim);
}




int
main(void) {
    char * s = "vamos a buscar";

    for ( int i=0; s[i]; i++) {
        assert(strrchr(s, s[i]) == wrapperStrrchrRec(s, s[i]));
        // printf("%s\n", wrapperStrrchrRec(s, s[i]));
    }

    assert(NULL == wrapperStrrchrRec(s, 'x'));

    // También tiene que dar NULL para el valor 0
    assert(NULL == wrapperStrrchrRec(s, '\0'));

    puts("OK!");
}