#include <stdio.h>

int j;
float x;
char probando;

/*
 * Me deja compilarlo pero no linkeditarlo
 * Cuando uso el comando gcc ej7.o me sale:
* Undefined symbols for architecture arm64:
*  "_main", referenced from:
*      <initial-undefines>
*ld: symbol(s) not found for architecture arm64
*clang: error: linker command failed with exit code 1 (use -v to see invocation)
*
*Supongo que el error es pq no hay ningun main entonces el programa no sabe por donde entrar
 */