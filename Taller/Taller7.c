#include <stdio.h>
#include <stdlib.h>
#include "../lib/getnum.h"

#define BLOCK   10
#define TAM    10




// int main() {
//     int *arr;
//
//     int i;
//     arr = malloc(TAM*sizeof (int));
//     for(; i<TAM; i++) {
//         arr[i] = 0;
//     }
//     mostrarArreglo(arr,TAM);
//     free(arr);
//
//
//     int *arr = NULL;
//     arr = realloc(arr, TAM*sizeof(int));
//     for(; i<TAM; i++) {
//         arr[i] = 0;
//     }
//
//     arr = calloc(10, sizeof(int));
// }
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

// int * cargarNumeros(int *dim) {
//     *dim = 0;
//     int num, repeat = 0;
//     int *arr = NULL;
//     int j=1;
//
//     do {
//         num = getint("Ingrese un numero: ");
//         for(int i=0; i<*dim && !repeat; i++) {
//             if(num == arr[i])
//                 repeat = 1;
//         }
//         if(*dim % BLOCK == 0) {
//             arr = realloc(arr, j * BLOCK * sizeof(int));
//
//         }
//         if(!repeat) {
//             arr[*dim] = num;
//             (*dim)++;
//         }
//     }
//     while (!repeat);
//
//     return arr;
// }
//
//
// int main(void) {
//     int dim;
//     int *arr;
//     arr = cargarNumeros(&dim);
//     for (int i = 0; i < dim; i++)
//         printf("%d ", arr[i]);
//     free(arr);
//     return 0;
// }
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

int main() {
    int c;
    char *v = calloc(BLOCK, sizeof(char));
    int i=0, j=1;
    for(; (c=getchar()) != '\n'; i++){
        if(i % BLOCK == 0) {
           v= realloc(v, BLOCK*j*sizeof(char));
            j++;
        }
        v[i] = c;
    }
    v = realloc(v, (i+1)*sizeof(char));

    for(int k = 0; k<i; k++) {
        printf("%c", v[k]);
    }
    free(v);
}

