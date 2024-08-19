#include <stdio.h>
/*
int main() {
    int espacios=0;
    for(int c = getchar(); c!='\n'; c=getchar()) {
        if(c == ' ')
            espacios++ ;
        else espacios=0;
        if(espacios <= 1) {
            printf("%c", c);
        }
    }
}
*/

int main() {
    for(int c = getchar(); c != '\n'; c=getchar()) {
        if (c=='\t' || c == '\b' || c == '/')
            printf("\\");
        else printf("%c", c);
    }
}