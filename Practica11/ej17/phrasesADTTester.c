#include "phrasesADT.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>


int 
main(void) {
    assert(newPhrasesADT(1200, 1100)==NULL);
    phrasesADT p = newPhrasesADT(1200, 1800);

    assert(put(p, 1199, "Hello" )==0);
    assert(size(p)==0);

    assert(put(p, 1200, "Hello" )==1);
    assert(put(p, 1210, ", " )==1);
    assert(put(p, 1220, "world" )==1);
    assert(size(p)==3);
    
    char * aux = get(p, 1100);
    assert(aux==NULL);
    aux= get(p, 1200);
    assert(strcmp(aux, "Hello")==0);
    free(aux);
    aux= get(p, 1210);
    assert(strcmp(aux, ", ")==0);
    free(aux);
    aux= get(p, 1220);
    assert(strcmp(aux, "world")==0);
    free(aux);
    
    aux = concatAll(p);
    assert(strcmp(aux, "Hello, world")==0);
    free(aux);
    
    aux = concat(p,1230, 1800);
    assert(strcmp(aux, "")==0);
    free(aux);
    
    aux = concat(p,1200, 1800);
    assert(strcmp(aux, "Hello, world")==0);
    free(aux);

    // reemplazamos "world" por otro texto
    assert(put(p, 1220, "mundo cruel." )==1);
    assert(size(p)==3);
    aux = concatAll(p);
    assert(strcmp(aux, "Hello, mundo cruel.")==0);
    free(aux);
    
    freePhrases(p);
    puts("OK!");
    return 0;
}

