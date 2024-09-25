#include <stdio.h>
#include <string.h>
#include <assert.h>
#define CHARS_DIM 256
#define CHARS 256


void analize(char text[], char chars[]) {
    char aux[CHARS] = {0};
    for(int i=0; text[i]; i++) {
        aux[text[i]] = 1;
    }
    int i=0;
    for(int k=0; k < CHARS; k++) {
        if(aux[k] == 1) {
            chars[i++] = k;
        }
    }
    chars[i] = 0;
}





int main(void) {
    char chars[CHARS_DIM];
    char chars2[CHARS_DIM];
    analize("El zorro mete la cola, pero no la pata!", chars);
    assert(strcmp(" !,Eacelmnoprtz", chars)==0);
    analize("ababababab", chars2);
    assert(strcmp("ab", chars2)==0);

    analize("", chars);
    assert(strcmp("", chars)==0);
    analize(".............................", chars);
    assert(strcmp(".", chars)==0);

    puts("OK!");
    return 0;
}