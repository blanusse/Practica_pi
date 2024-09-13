#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define MAYOR   31
#define MENOR 30
#define LEN 10
#define esBisiesto(a)   ((a)%4 == 0 && (a)%100 != 0) || (a)%400 == 0
enum meses {ENE=1, FEB, MAR, ABR, MAY, JUN, JUL, AGO, SEP, OCT, NOV, DIC};
#define esMayor(a)      (a) == 1 || (a) == MAR || (a) == MAY || (a) == JUL || (a) == AGO || (a) == OCT || (a) == DIC



int validMonth(int m) {
    return (m >= ENE && m <= DIC);
}

int validYear (int y) {
    return y>0;
}

int validDate (int d, int m, int y) {
    int dayTab[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    //Esa matriz tiene en una fila los limites de dias para un anio no bisiesto
    // y en la segunda fila los limites de dias para un anio bisiesto
    int error = 0;
    int bisiesto = esBisiesto(y);
    if(d > dayTab[bisiesto][m-1]) {
        error = 1;
    }

    return !error;
}


int valorFecha(const char *v, unsigned int *day, unsigned int *month, unsigned int *year) {
    int error = 0;
    if (strlen(v) == LEN) {
        int d = atoi(v);
        int m = atoi ((v+3));
        int y = atoi(v+6);
        if (validMonth(m) && validYear(y) && validDate(d, m, y)) {
            *day = d;
            *month = m;
            *year = y;
        }
        else error = 1;
    }
    else error = 1;
    return !error;

}


int main(void) {
    unsigned int d=100, m=200, a=300;
    int res;
    res = valorFecha("", &d, &m, &a);
    assert(res==0);
    assert(d==100);
    assert(m==200);
    assert(a==300);
    printf("%d\n", 1);

    res = valorFecha("29/02/1999", &d, &m, &a);
    assert(res==0);
    assert(d==100);
    assert(m==200);
    assert(a==300);
    printf("%d\n", 2);


    res = valorFecha("30/14/2020", &d, &m, &a);
    assert(res==0);
    assert(d==100);
    assert(m==200);
    assert(a==300);
    printf("%d\n", 3);


    res = valorFecha("12/12/", &d, &m, &a);
    assert(res==0);
    assert(d==100);
    assert(m==200);
    assert(a==300);
    printf("%d\n", 4);

    res = valorFecha("1/1/2000", &d, &m, &a);
    assert(res==0);
    assert(d==100);
    assert(m==200);
    assert(a==300);
    printf("%d\n", 5);

    res = valorFecha("12/01/2000", &d, &m, &a);
    assert(res==1);
    assert(d==12);
    assert(m==1);
    assert(a==2000);
    printf("%d\n", 6);

    res = valorFecha("29/02/1900", &d, &m, &a);
    assert(res==0);
    assert(d==12);
    assert(m==1);
    assert(a==2000);
    printf("%d\n", 7);

    res = valorFecha("29/02/2000", &d, &m, &a);
    assert(res==1);
    assert(d==29);
    assert(m==2);
    assert(a==2000);
    printf("%d\n", 8);

    printf("OK");
    return 0;
}




//