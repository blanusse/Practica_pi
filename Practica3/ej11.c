#include <stdio.h>
int main(void) {
    printf("%-8s %-10s %-9s %s\n", "N", "N*10", "N*100", "N*1000");
    for(int n=1;n<=20;n++) {
        printf("%-10.d %-10.d %-10.d %-10.d\n", n, n*10, n*100, n*1000);
    }
}
