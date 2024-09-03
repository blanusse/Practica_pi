#include <math.h>
#include <assert.h>
#include <stdio.h>
#define M   5
#define N   4

int armaFilas(int a[][M], int r[N]) {
    int c=0;
    for(int i=0; i<N; i++) {
        int flag=0;
        r[c] = 0;
        for(int k=0; k<M && flag==0; k++) {
            if ( a[i][k] < 10 && a[i][k] >= 0) {
                r[c] += (pow(10, M-1-k) * a[i][k]);
            }
            else {
                r[c] = 0;
                c--;
                flag = 1;
            }
        }
        c++;
    }
    return c;
}

/*
int main() {
    int m1[N][M] = { { 1,2,3,4,5},
                   { 1,2,13,4,5},
                   { 1,2,4,4,5},
                   { 1,2,-3,4,5}};
    int v[N];
    int dimV = armaFilas(m1, v);
    for (int i=0; i<dimV; i++)
        printf("%d\n", v[i]);
}
*/

int main(void)
{
    int m1[N][M] = { { 1,2,3,4,5},
               { 1,2,13,4,5},
               { 1,2,4,4,5},
               { 1,2,-3,4,5}};
    int vec[N];
    int n = armaFilas(m1, vec);
    assert(n==2);
    assert(vec[0]==12345);
    assert(vec[1]==12445);

    int m2[N][M] = { { 1,0,3,4,5},
                { 0,2,1,4,5},
                { 9,9,9,9,9},
                { 0,0,1,4,5}};
    n = armaFilas(m2, vec);
    assert(n==4);
    assert(vec[0]==10345);
    assert(vec[1]==2145);
    assert(vec[2]==99999);
    assert(vec[3]==145);


    int m3[N][M] = { { 11,0,3,4,5},
                { 0,2,1,14,5},
                { 9,9,9,91,9},
                { 0,0,1,14,5}};
    n = armaFilas(m3, vec);
    assert(n==0);


    printf("OK!\n");
    return 0;
}
