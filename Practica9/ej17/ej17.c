#include <stdio.h>
#include <assert.h>
#include <ctype.h>


int bienFormado(char palabra[]) {
    if(*palabra == 0)
        return 0;
    int aux = bienFormado(palabra+1);

    if(aux != 0 && isdigit(*palabra)) {
        return -1;
    }
    if(aux == 0 && isdigit(*palabra)) {
        return *palabra - '0';
    }
    if(aux == 0 && isalpha(*palabra)) {
        return -1;
    }
    if(aux != 0 && isalpha(*palabra)) {
        return aux-1;
    }
    if(!isalpha(*palabra) && !isdigit(*palabra))
        return -1;
}


int main(void) {
    char * zero[]={"abcd4a10bb2", "", "0000", "a1", "abc3", "0a1"};

    char * not_zero[] ={ "a", "1", "a2", "abc2", "abc4", "abc33", "0123", "2aa", "$1", "@@2", "abcd22", "@@"};

    for(int i=0; i < sizeof(zero)/sizeof(zero[0]);i++) {
        printf("%s\n", zero[i]);
        assert(bienFormado(zero[i])==0);
    }

    for(int i=0; i < sizeof(not_zero)/sizeof(not_zero[0]);i++) {
        printf("%s\n", not_zero[i]);
        assert(bienFormado(not_zero[i]) !=0);
    }

    puts("OK!");
    return 0;
}