#include <stdio.h>
int main(void) {
    int c, mayor=0;
    while((c=getchar())!=EOF)
    {
        if (c>mayor)
            mayor=c;

    }
    printf("%d", mayor);
}