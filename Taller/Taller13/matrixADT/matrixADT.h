#include <stdlib.h>



typedef struct matrixCDT * matrixADT;

typedef int elementType;

/* Crea una nueva matriz de elementos enteros.
** Inicialmente la matriz estÃ¡ vacÃ­a.
** Si no se pudo crear retorna NULL.
 */
matrixADT newMatrix();

/* Libera todos los recursos reservados por el TAD */
void freeMatrix(matrixADT m);

/* Agrega un elemento a la matriz en la posiciÃ³n [row][col].
** De ser necesario agranda la matriz.
** Si no lo pudo agregar o los parÃ¡metros son incorrectos retorna 0, sino 1.
** Si la posiciÃ³n estaba ocupada pisa el elemento que habÃ­a.
** m: matriz
** row: fila (mayor o igual a cero)
** col: columna ( mayor o igual a cero)
** elem: valor a insertar.
 */
int setElement(matrixADT m, size_t row, size_t col, elementType elem);

/* Si existe un elemento en la posiciÃ³n [row][col], lo deja en out y retorna 1.
** Si no habÃ­a un elemento en esa posiciÃ³n retorna 0.
 */
int getElement(matrixADT m, size_t row, size_t col, elementType * out);

/* Cantidad de filas que tiene la matriz */
size_t rows(matrixADT m);