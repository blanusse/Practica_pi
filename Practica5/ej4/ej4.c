#include <stdio.h>
#include <stdlib.h>


double randNormalize(void) {
    return rand() / ((double) RAND_MAX+1);
}

int randInt(int left ,int rigth) {
    return (int) (randNormalize()*(rigth - left + 1)) + left;
}

int main() {
    randomize();
    for (int i=0; i<20; i++) {
        printf("%d\n", randInt(1, 4));
    }
}