#include <stdio.h>
#include <assert.h>
#include <string.h>

int invierte(char original[], char copia[]) {
    if(*original == 0)
        return 0;

    int count = invierte(original+1, copia);
    copia[count] = original[0];
    return count + 1;
}




int main(void) {

    char s[20] = {0};

    invierte("1234567890", s);
    assert(strcmp(s, "0987654321")==0);

    memset(s, 0, 20);
    invierte("", s);
    assert(strcmp(s, "")==0);

    memset(s, 0, 20);
    invierte("a", s);
    assert(strcmp(s, "a")==0);

    memset(s, 0, 20);
    invierte("ab", s);
    assert(strcmp(s, "ba")==0);

    memset(s, 0, 20);
    invierte("abc", s);
    assert(strcmp(s, "cba")==0);

    printf ("OK!\n");
    return 0;
}