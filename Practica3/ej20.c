#include <stdio.h>
#define EPS 0.0000000001

int main(void) {
    double epsilon=1, prev=0;
    int factorial=1;
    printf("%-10s %-10s\n", "N", "e");
    for(int n=1; (epsilon - prev) > EPS; n++) {
        prev = epsilon;
        printf("%-10d %-10.8f\n", n, epsilon);
        factorial*=n;
        epsilon+=1.0/factorial;
    }
    return 0;
}
