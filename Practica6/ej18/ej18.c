#include <stdio.h>
#include <assert.h>
#define COLS 4

int vectorAmigo (const int a[], const int b[]) {
    int acum=0;
    for( int i=0; i< COLS; i++) {
        int itIs = 0;
        for(int k =0; k<COLS && itIs == 0; k++) {
            if(a[i] == b[k])
                itIs = 1;
        }
        if (itIs == 1)
            acum++;
    }
    //return acum/COLS;
    if(acum == COLS)
        return 1;
    return 0;
}


int sonAmigas (const int a[][COLS], unsigned int filA, const int b[][COLS], unsigned int filB) {
    int cont1 = 0, cont2 = 0;
    for(int i=0; i<filA; i++) {
        for(int k=0; k<filB; k++) {
            if (vectorAmigo(a[i], b[k]))
                cont1++;
            if (vectorAmigo(b[k], a[i]))
                cont2++;
        }
    }
    if (cont1 == filA)
        return 1;
    if (cont2 == filB)
        return 2;
    return 0;
}

/*
int main() {
    int a[] = {1, 2, 2, 3};
    int b[] = {0, 1, 2, 3};
    int c[] = {1, 2, 3, 4};
    return vectorAmigo(b, a);

}*/


int
main(void)
{
    int m1[][COLS] = {{0,1,2,3}, {4,4,5,6}, {7,8,8,9}};
    int m2[][COLS] = {{0,1,2,3}, {-3,7,8,9}, {-1,3,4,7}, {4,5,6,8}};
    int m3[][COLS] = {{2,3,3,7}};
    assert(sonAmigas(m1,3,m2,4)==1);
    assert(sonAmigas(m1,1,m2,4)==1);
    assert(sonAmigas(m1,2,m2,4)==1);
    assert(sonAmigas(m1,2,m2,2)==0);/**/
    assert(sonAmigas(m2,4,m1,3)==2);
    assert(sonAmigas(m1,3,m3,1)==0);
    assert(sonAmigas(m3,1,m1,3)==0);
    int res = sonAmigas(m1,3,m1,3);
    assert(res==1 || res==2);

    printf("OK!\n");

    return 0;
}