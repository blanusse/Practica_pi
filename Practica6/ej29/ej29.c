#include <stdio.h>
#include <assert.h>
#include <string.h>


void deleteChars(char a[], char b[]){

    int i=0, j=0, k=0;
    for(;a[i] && b[i]; i++) {
        if(a[i] != b[i]) {
            a[j++] = a[i];
            b[k++] = b[i];
        }
    }
    if(a[i]) {
        while(a[i]) {
            a[j++] = a[i];
            i++;
        }
    }
    else {
        while(b[i]) {
            b[k++] = b[i];
            i++;
        }
    }

    a[j] = 0;
    b[k] = 0;
}


int main(void) {

    char s3[] = "abc";
    char s4[] = "axc123456789012345678901234567890";
    deleteChars(s3,s4);
    assert(strcmp(s3, "b")==0);
    assert(strcmp(s4, "x123456789012345678901234567890")==0);

    char s1[] = "Hola, soy un string";
    char s2[] = "Yo soy otro string";

    deleteChars(s1, s2);
    assert(strcmp(s1, "Hla, sy un string")==0);
    assert(strcmp(s2, "Y soy tro string")==0);

    char empty[] = "";
    deleteChars(s1, empty);
    assert(strcmp(s1, "Hla, sy un string")==0);
    assert(strcmp(empty, "")==0);

    strcpy(s1, "ABCDE");
    strcpy(s2, "abcde");
    deleteChars(s1, s2);
    assert(strcmp(s1, "ABCDE")==0);
    assert(strcmp(s2, "abcde")==0);

    deleteChars(s1,s1);
    assert(strcmp(s1, "")==0);

    puts("OK!");
    return 0;
}


