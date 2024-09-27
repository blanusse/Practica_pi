#include <ctype.h>
#include <stdio.h>

int notacionExp(char text[], char ans[]) {
    int error = 0;
    for(int i=0; !error &&  text[i]; i++) {
        if(!isdigit(text[i]) && text[i] != '.') {
            error = 1;
        }
        if(text[i] != '0' && text[i] != '.') {

        }
    }


}
