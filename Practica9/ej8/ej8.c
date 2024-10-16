#include <stdio.h>
#include <assert.h>

int ackermann(unsigned int a, unsigned int b) {
    if(a ==0 && b == 0)
        return 1;
    if(a==0) {
        return b+1;
    }
    if(b==0) {
        return ackermann(a-1, 1);
    }
    return ackermann(a-1, ackermann(a, b-1));
}

int main(void) {

    for(int i=0; i < 100; i++)
        assert(ackermann(0, i)==i+1);

    assert(ackermann(3,0)==5);
    assert(ackermann(3,2)==29);

    puts("Wait for it...");

    assert(ackermann(4,1)==65533);

    puts("Legendary!");
    return 0;
}
