#include <stdio.h>
#include <string.h>
#include <assert.h>

//
// int strend(char text[], char end[]) {
//     int error = 0;
//     int i=strlen(text), k=strlen(end);
//     for(; !error && k>=0 && k<=i;i-- , k--) {
//         if(text[i] != end[k])
//             error = 1;
//     }
//     //Me fijo si se chequeo todo el vector de end
//     if(k>0) {
//         error = 1;
//     }
//     return !error;
// }
//
//
// int main(void) {
//     assert(strend("","")==1);
//     assert(strend("something","")==1);
//     assert(strend("something","thing")==1);
//     assert(strend("something","something")==1);
//     assert(strend("something","plus something")==0);
//     assert(strend("not at the eeeeeend"," end")==0);
//     assert(strend("not at the eeeeeennnnnd","end")==0);
//     assert(strend("","s")==0);
//     assert(strend("ssss","sss")==1);
//     assert(strend("ssss","sssss")==0);
//     puts("OK!");
//     return 0;
// }




void my_strncpy(char s[], const char t[], unsigned int n) {
    int i=0;
    for(; i<n && t[i]; i++)
        s[i] = t[i];
    s[i] = 0;
}


int my_strncmp(const char s[], const char t[], unsigned int n) {
    int error = 0;
    int i=0;
    for(; !error && t[i] && s[i] && i<n; i++) {
        if(s[i] != t[i])
            error = s[i]-t[i];
    }
    return error;
}

int my_strncat(char s[], const char t[], unsigned int n) {
    int i=0;
    int length = strlen(s);
    for(; t[i] && i<n; i++) {
        s[length+i] = t[i];
    }
    s[length+i] = 0;
    return s;
}


int main(void) {
    char s[100];
    for(int i=0;i<100;i++)
        s[i]='x';
    assert(my_strncpy(s,"prueba copiar",100)==s);
    assert(strcmp(s,"prueba copiar")==0);
    for(int i=strlen(s); i < 100;i++)
        assert(s[i]=='\0');

    my_strncpy(s,"",100);
    for(int i=0; i < 100;i++)
        assert(s[i]=='\0');

    my_strncpy(s,"123456",4);
    assert(strcmp(s,"1234")==0);

    my_strncpy(s,"777777777",2);
    assert(strcmp(s,"7734")==0);

    // assert(my_strncat(s, " end",10)==s);
    // assert(strcmp(s,"7734 end")==0);
    //
    // assert(my_strncat(s, "abcde",2)==s);
    // assert(strcmp(s,"7734 endab")==0);
    //
    // assert(my_strncmp(s,"7734 endab",10)==0);
    // assert(my_strncmp(s,"7734 endab",12)==0);
    // assert(my_strncmp(s,"7734",4)==0);
    // assert(my_strncmp(s,"7735",4)<0);
    // assert(my_strncmp(s,"7732",4)>0);
    // assert(my_strncmp(s,"7734",0)==0);
    // assert(my_strncmp(s,"",4)>0);
    // assert(my_strncmp(s,"",0)==0);

    printf("OK\n");
    return 0;
}