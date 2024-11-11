#ifndef TEORICAS_C_BOOLMATADT_H
#define TEORICAS_C_BOOLMATADT_H

#include <stdlib.h>

/**
 * Se desea implementar una matriz booleana "infinita" (cada elemento es 1 ó 0)
 * Se sabe que la gran mayoría de los elementos tienen el valor 0 (falso).
 *
 * Ejercicio de Parcial 1C Año 2011
 */
typedef struct boolMatCDT * boolMatADT;

typedef enum {false=0, true} boolean;

/*
 * Crea una matriz con todos los elementos en falso
 */
boolMatADT newBoolMat(void);

/*
** m[row][col] = true
*/
void setTrue(boolMatADT m, size_t row, size_t col);

/*
** m[row][col] = false
*/
// T.ODO Implementar
void setFalse(boolMatADT m, size_t row, size_t col);

/*
 * Retorna el valor almacenado en m[row][col]
 */
boolean getValue(const boolMatADT m, size_t row, size_t col);

/*
 * Libera toda la memoria reservada
 */
void freeBoolMat(boolMatADT m);

#endif //TEORICAS_C_BOOLMATADT_H
