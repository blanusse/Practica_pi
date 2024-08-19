#include <stdio.h>
#include "getnum.h"

int
main(void)
{
	int i, j, n = 0, suma = 0; /* Asigna como int a todas las variables*/
	while( n <= 0 ) /*Hasta que no se ingrese un valor mayor a cero, seguira el loop*/
		n = getint("Ingrese cantidad de elementos:");

	for(i=1; i<=n; i++) /*por cada numero en el valor ingresado, se corre el for*/
	{
		j = getint("Ingrese valor %d:",i);
		suma += j; /*Se almacena el valor ingresado*/
	}

	printf("El resultado es : %.2f\n", suma / (float) j);
	return 0;	
}
