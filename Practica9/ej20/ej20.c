#include <stdio.h>
int main() {
for(int i = 1; i!=22; i++) {
printf("add_executable(Prac11.%d Practica11/ej%d/ej%d.c Lib/getnum.c Lib/random.c)\n", i, i, i);
}
return 0;
}