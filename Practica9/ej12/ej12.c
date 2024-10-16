#include <stdio.h>
#include <assert.h>


int balance(const char a[]) {
    if(*a == 0) {
        return 0;
    }

    if(*a == '(') {
        return 1 + balance(++a);
    }
    if(*a == ')')
        return -1 + balance(++a);
    return balance(++a);
}

int main(void) {

    assert(balance("")==0);
    assert(balance("((()))")==0);
    assert(balance(")(")==0);
    assert(balance("()()")==0);
    assert(balance(")))(((")==0);
    assert(balance("))) ((( ))( ()() ()()(")==0);

    assert(balance(")")!=0);
    assert(balance("(")!=0);
    assert(balance(")()")!=0);
    assert(balance(" ) ")!=0);
    assert(balance("))))))))))))))))))))))))))))))))))))))))))))))))))))))")!=0);
    assert(balance("))))))))))))))))))))))))))))))))))))))))))))))))))))))((((((((((((")!=0);

    printf ("OK!\n");
    return 0;
}