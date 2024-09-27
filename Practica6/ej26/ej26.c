#include <stdio.h>
#include <assert.h>
#include <string.h>



// void insertaDesde(char a[], char b[], char letter) {
//     int appear = 0, i=0;
//     for(; !appear && a[i] != '\0'; i++) {
//         if (a[i] == letter) {
//             appear = 1;
//             i--;
//         }
//     }
//     for(int k=0;appear && b[k] != '\0'; k++) {
//         a[i++] = b[k];
//     }
//     a[i] = '\0';
// }

void insertaDesde(char a[], char b[], char letter) {
    char *appear = strchr(a, letter);
    if(appear != NULL) {
        strcpy(appear, b);
    }
}



int main(void) {
    char str1[60] = "manuel";
    char str2[] = "javi";
    insertaDesde(str1, str2,'n');
    assert(strcmp(str1,"majavi")==0);

    char str3[20];
    strcpy(str3, "manuel");
    insertaDesde(str3, "javi" ,'l');
    assert(strcmp(str3,"manuejavi")==0); // muestra manuejavi

    char str4[60];
    strcpy(str4, "lalala");
    insertaDesde(str4, "javi",'j');
    assert(strcmp("lalala",str4)==0);

    insertaDesde(str4, "javier ibaniez de toledo",'l');
    assert(strcmp("javier ibaniez de toledo",str4)==0);

    strcpy(str4,"12345");
    insertaDesde(str4, "6789abcdefgh",'5');
    assert(strcmp("12346789abcdefgh",str4)==0);


    puts("OK!");
    return 0;
}