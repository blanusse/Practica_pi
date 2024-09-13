#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define OK  1
#define ERROR !OK
#define esBisiesto(a)   ((a)%4 == 0 && (a)%100 != 0) || (a)%400 == 0
enum meses {ENE=1, FEB, MAR, ABR, MAY, JUN, JUL, AGO, SEP, OCT, NOV, DIC};

#define EPSILON     0.000001




//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
//EJ1


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

int unDiaMas(int *day, int *month, int *year) {
    if(*day > 0 && *month >= ENE && *month <= DIC && *year > 0) {
        int dayTab[2][DIC] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
        int bisiesto = esBisiesto(*year);

        if(*day == dayTab[bisiesto][*month-1] && *month==DIC) {
            *day = 1;
            *month = 1;
            (*year)++;
        }
        else if(*day == dayTab[bisiesto][*month-1] && *month != DIC) {
            *day = 1;
            (*month)++;
        }
        else {
            (*day)++;
        }
        if(!validDate(*day, *month, *year)) {
            return ERROR;
        }
        return OK;
    }
    return ERROR;
}





//
// int main(void)
// {
//     int dia, mes, anio;
//
//
//     dia = 9, mes = 4, anio = 2021;
//     printf("Fecha actual: %d/%d/%d\n", dia, mes, anio);
//     if (unDiaMas(&dia, &mes, &anio))
//         printf("Fecha con un dia mas: %d/%d/%d\n", dia, mes, anio);
//     else
//         printf("Error en los datos\n");
//
//
//     dia = 1, mes = 1, anio = 2021;
//     assert(unDiaMas(&dia, &mes, &anio) == OK);
//     assert(dia == 2 && mes == 1 && anio == 2021);
//
//
//     dia = 31, mes = 3, anio = 2021;
//     assert(unDiaMas(&dia, &mes, &anio) == OK);
//     assert(dia == 1 && mes == 4 && anio == 2021);
//
//
//     dia = 31, mes = 12, anio = 2020;
//     assert(unDiaMas(&dia, &mes, &anio) == OK);
//     assert(dia == 1 && mes == 1 && anio == 2021);
//
//
//     printf("OK!\n");
//     return 0;
// }
//
//
// static int
// bisiesto(int anio)
// {
//     int esb = 0;
//     if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)
//         esb = 1;
//     return esb;
// }

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
//EJ2

//
// int solucionCuadratica(int a, int b, int c, float *r1, float *r2) {
//     int raices = 0;
//     int discr = pow(b, 2) - 4* a * c;
//     if(discr < 0) {
//         raices = 0;
//     }
//     else if (discr == 0) {
//         raices = 1;
//         *r1 = -b/(2*a);
//         *r2 = -b/(2*a);
//     }
//     else {
//         raices = 2;
//         *r1 = (-b + sqrt(discr)) / (2 *a);
//         *r2 = (-b - sqrt(discr)) / (2 *a);
//     }
//     return raices;
// }
//
//
// int
// main(void) {
//     float r1, r2;
//     assert(solucionCuadratica(1, -2, 1, &r1, &r2) == 1); // x^2 - 2x + 1
//     assert(fabs(r1 - 1.0) < EPSILON);
//     assert(fabs(r2 - 1.0) < EPSILON);
//
//     assert(solucionCuadratica(2, 1, 0, &r1, &r2) == 2); // 2 x^2 + x
//     assert(fabs(r1 - 0.0) < EPSILON); // Podria ser r1 = -0.5 y r2 = 0
//     assert(fabs(r2 - -0.5) < EPSILON);
//
//     assert(solucionCuadratica(1, 0, 1, &r1, &r2) == 0); // x^2 + 1
//
//     printf("\nOK!\n");
//     return 0;
// }

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
//EJ3

//
// int incrementoFCMinMax(int angulos[], int distancias[], int dim, int *fMin, int *cMin, int *fMax, int *cMax) {
//     if(dim > 0) {
//         int dMax=distancias[0], dMin=distancias[0], placeMax=distancias[0], placeMin = distancias[0];
//         int matDir[8][2] = {{0,1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}};
//         for(int i=0; i<dim; i++) {
//             if (distancias[i] >= dMax) {
//                 dMax = distancias[i];
//                 placeMax = i;
//             }
//
//             if (distancias[i] <= dMin) {
//                 dMin = distancias[i];
//                 placeMin = i;
//             }
//         }
//
//         int angMin = angulos[placeMin]/45;
//         int angMax = angulos[placeMax]/45;
//
//
//         *fMin = matDir[angMin][0];
//         *cMin = matDir[angMin][1];
//
//         *fMax = matDir[angMax][0];
//         *cMax = matDir[angMax][1];
//         return 1;
//     }
//     return 0;
// }
//
// int main()
// {
//     int angulos[] = {0, 45, 90, 135, 180, 225, 270, 315};
//     int distancias[] = {1, 2, 3, 4, 5, 6, 7, 8};
//     int fMin, cMin, fMax, cMax;
//     assert(incrementoFCMinMax(angulos, distancias, sizeof(angulos) / sizeof(angulos[0]), &fMin, &cMin, &fMax, &cMax) == 1);
//     printf("%d\t%d\t%d\t%d", fMin, cMin, fMax, cMax);
//      assert(fMin == 0 && cMin == 1 && fMax == 1 && cMax == 1);
//
//
//      int angulos2[] = {0, 45, 90, 135, 180, 225, 270, 315};
//      int distancias2[] = {8, 7, 6, 5, 4, 3, 2, 1};
//      assert(incrementoFCMinMax(angulos2, distancias2, sizeof(angulos2) / sizeof(angulos2[0]), &fMin, &cMin, &fMax, &cMax) == 1);
//      assert(fMin == 1 && cMin == 1 && fMax == 0 && cMax == 1);
//
//
//      int angulos3[] = {45, 90, 135, 225, 180, 0};
//      int distancias3[] = {12, 1, 4, 20, 7, 9};
//      assert(incrementoFCMinMax(angulos3, distancias3, sizeof(angulos3) / sizeof(angulos3[0]), &fMin, &cMin, &fMax, &cMax) == 1);
//      assert(fMin == -1 && cMin == 0 && fMax == 1 && cMax == -1);
//
//
//      int angulos4[] = {90};
//      int distancias4[] = {1};
//      assert(incrementoFCMinMax(angulos4, distancias4, sizeof(angulos4) / sizeof(angulos4[0]), &fMin, &cMin, &fMax, &cMax) == 1);
//      assert(fMin == -1 && cMin == 0 && fMax == -1 && cMax == 0);
//
//
//      assert(incrementoFCMinMax(NULL, NULL, 0, &fMin, &cMin, &fMax, &cMax) == 0);
//      assert(fMin == -1 && cMin == 0 && fMax == -1 && cMax == 0); // no debería modificar los valores
//
//
//      puts("OK");
//      return 0;
// }

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
//EJ4


void eliminaRepetidas(char v[]) {
    if (v != NULL) {
        int k=0;
        for(int i=0; v[i] != '\0'; i++) {
            if (toupper(v[i]) != toupper(v[i+1])) {
                v[k] = v[i];
                k++;
            }
        }
        v[k] = '\0';
    }
}

// int main() {
//     char c[] = "Gol de argentina goool de Messi";
//     eliminaRepetidas(c);
//     for(int i=0; c[i] != '\0'; i++)
//         printf("%c", c[i]);
// }


int main() {
    char str1[] = "gooooooooooooooooool     de    Argentinaaaaaaaaaaaaaaaaaaaaaaaaa gol de Messssssssiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii";
    eliminaRepetidas(str1);
    assert(strcmp(str1, "gol de Argentina gol de Mesi") == 0);
    eliminaRepetidas(str1);
    assert(strcmp(str1, "gol de Argentina gol de Mesi") == 0);


    char str2[] = "aaaaaaaa";
    eliminaRepetidas(str2);
    assert(strcmp(str2, "a") == 0);


    char str3[] = "abcabcabcabczzzzzza";
    eliminaRepetidas(str3);
    assert(strcmp(str3, "abcabcabcabcza") == 0);


    eliminaRepetidas(NULL);


    char str4[] = "a";
    eliminaRepetidas(str4);
    assert(strcmp(str4, "a") == 0);


    char str5[] = "";
    eliminaRepetidas(str5);
    assert(strcmp(str5, "") == 0);


    char str_break[] = "a"; // por qué no rompe el programa? forzar un error modificando el string
    eliminaRepetidas(str_break);


    puts("OK");
    return 0;
}



















