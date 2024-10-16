#include <stdio.h>
int main() {
for(int i = 1; i!=9; i++) {
printf("add_executable(Prac8.%d Practica8/ej%d/ej%d.c Lib/getnum.c Lib/random.c)\n", i, i, i);
}
return 0;
}