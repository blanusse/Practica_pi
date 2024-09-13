#include <stdio.h>
#include <assert.h>
#include <string.h>

//Me ayude con la respuesta :(
void spaceDeleter (char *v) {
    int i, k;
    for( i = k =0; v[i] != '\0'; i++) {
        if(i == 0 || !(v[i] == ' ' && v[i-1] == ' ')) {
            v[k] = v[i];
            k++;
        }
    }
    v[k] = '\0';
}













int main(void) {
char s[60] = "   "; // cant impar de blancos
spaceDeleter(s);
assert(strcmp(s, " ")==0);

spaceDeleter(s);
assert(strcmp(s, " ")==0);

strcpy(s,"  ");
spaceDeleter(s);
assert(strcmp(s, " ")==0);

strcpy(s," . . .  ");
spaceDeleter(s);
assert(strcmp(s, " . . . ")==0);

strcpy(s,"");
spaceDeleter(s);
assert(strcmp(s, "")==0);

strcpy(s,"sinblancos");
spaceDeleter(s);
assert(strcmp(s, "sinblancos")==0);



printf("OK!\n");
return 0;
}
