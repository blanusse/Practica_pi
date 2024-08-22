#include <stdio.h>

#include "../Lib/getnum.h"

int main() {
   int num = getint("Ingresar un numero entero positivo: "), contadorUnos=0;
   int original= num;
   for (int potencia=32768; potencia>0; potencia /= 2) {
      if (num>=potencia) {
         contadorUnos++;
         num = num-potencia;
      }
   }
   printf("Hay %d unos en el binario de %d", contadorUnos, original);
   return 0;
}

/*cuando se usa entrada estandar es mejor usar el while*/






