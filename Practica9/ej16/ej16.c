#include <stdio.h>
#include <assert.h>

int orden(const int v[]) {
    if(*v == -1 || *(v+1) == -1)
        return 0;
    if(*(v+2) == -1 && *v != *(v+1))
        return *v > *(v+1) ? -1:1;
    if(*v > *(v+1)) {
        if(orden(v+1) == -1)
            return -1;
    }
    if(*v < *(v+1))
        if(orden(v+1) == 1)
            return 1;
    return 0;
}

int main(void) {

    int v[] = {-1};
    assert(orden(v)==0);

    int v2[] = {1,-1};
    assert(orden(v2)==0);

    int v3[] = {1,2,-1};
    assert(orden(v3)==1);

    int v4[] = {1,2,3,10,100,999,2345,-1};
    assert(orden(v4)==1);

    int v5[] = {100,29,23,19,18,5,4,0,-1};
    assert(orden(v5)==-1);

    int v6[] = {1,2,3,10,100,999,998,-1};
    assert(orden(v6)==0);

    int v7[] = {1,2,3,10,1000,999,1998,-1};
    assert(orden(v7)==0);

    int v8[] = {1,1,1,10,1000,1999,2998,-1};
    assert(orden(v8)==0);

    int v9[] = {1,1,-1};
    assert(orden(v9)==0);

    printf ("OK!\n");
    return 0;
}
