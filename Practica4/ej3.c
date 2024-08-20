#include <stdio.h>
# define PI 3.14159265
#define VOLUMEN(r) (4/3) * PI * (r)*(r)*(r)

int main(void) {
    printf("Radio\t\tVolumen\n");
    for (int i=1; i<=10; i++) {
        printf("%f\t\t%d\n", i, VOLUMEN(i));
    }
}