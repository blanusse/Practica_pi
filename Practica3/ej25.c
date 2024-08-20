#include <ctype.h>
#include <stdio.h>
int main() {
   for(int c=getchar(); c!='\n'; c=getchar()) {
       if (!isspace(c)) {
           putchar(toupper(c));
       }
   }
}

/*cuando se usa entrada estandar es mejor usar el while*/






