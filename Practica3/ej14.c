#include <stdio.h>
int main(void) {
    int anterior=10000, mayus=0, minus=0;
    for (int c=getchar();c==32 || (c>=65 && c<=90) || (c>=97 && c<=122);c=getchar()) {
        if(anterior>c && c!=' ')
            anterior=c;
        if(c>=65 && c<=90)
            mayus+=1;
        else if(c>=97&&c<=122)
            minus+=1;
    }
    printf("%c ; %d mayusculas, %d minusculas", anterior, mayus, minus);
}