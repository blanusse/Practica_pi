#include <assert.h>
#include <stdio.h>
#include "../Lib/random.h"

int main(void) {
    randomize();
    for(int i = 0; i < 100000; i++) {
        int aux = randInt(1, 6);
        assert(aux >= 1 && aux <=6);
    }
    puts("OK!");
    return 0;
}