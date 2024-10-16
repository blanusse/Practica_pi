#include <stdio.h>

char *strpbrkRec(char *text, char *search) {
    static int flag = 0;
    if(*text == 0)
        return 0;
    if(*search == 0) {
        flag = 0;
    }
    if(*text == *search) {
        flag = 1;
    }
    if(flag && *text != *search)
        return NULL;
    strpbrkRec(++text, ++search);
}