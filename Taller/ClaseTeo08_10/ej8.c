#include <stdio.h>

void factorial(int num, int *fact) {
    if(num==0) {
        *fact = 1;
        return;
    }
    factorial(num-1, fact);
    *fact *= num;
}


int cociente(int a, int b, int *resto) {

    if(a<b) {
        *resto = a;
        return a/b;
    }

}