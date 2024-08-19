#include "tp1_12.h"


int
main(void)
{
    int i = FALSE;
    int j = TRUE;
    return 0;
}

/*
# 1 "ej12.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 418 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "ej12.c" 2
# 1 "./tp1_12.h" 1



float nada(void);
# 2 "ej12.c" 2


int
main(void)
{
    int i = ! 1;
    int j = 1;
    return 0;
}

*
*En el preprocesamiento, con el comando include se busca al archivo elegido,
*y adopta los "alias" con el comando #define, entonces cdo se corre el codigo del archivo fuente,
*se reemplaza la palabra FALSE por un !1 y la palabra TRUE por un 1, entonces al ser numeros enteros, quedan
*definidos como i=-1 y j=1
 */