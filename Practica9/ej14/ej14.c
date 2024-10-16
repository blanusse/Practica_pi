#include <stdio.h>
#include <assert.h>

int apareados(const char *texto)
{
    if(*texto==0) return 0;
    int aux = apareados(texto+1);
    if(aux>0)
        return aux;
    if(*texto=='(')
        return aux + 1;
    if(*texto==')')
        return aux - 1;
}


int main(void) {

    assert(apareados("")==0);
    assert(apareados("()")==0);
    assert(apareados("(())()(()())")==0);
    assert(apareados("((((()))))")==0);

    assert(apareados("(")!=0);
    assert(apareados(")")!=0);
    assert(apareados("(")!=0);
    assert(apareados("())")!=0);
    assert(apareados("()(")!=0);
    assert(apareados("((()))())(")!=0);

    int dim=100000;
    char s[dim+1];
    for(int i=0; i<dim/2; i++) {
        s[i] = '(';
        s[dim-1-i] = ')';
    }
    s[dim]=0;
    assert(apareados(s)==0);
    for(int i=1; i < dim/100; i++) {
        assert(apareados(s+i)!=0);
    }

    puts("OK!");
    return 0;
}
