#include <stdio.h>
int
main (void)
{
	float x, y, z;
	x= getfloat("Ingrese un n�mero real :");
	putchar('\n');

	y = f1(x);
	z = f2(x);

	printf("El doble de %g es %g\n",x, y);
	printf("El triple de %g es %g\n",x , z);
	return 0;
}

float
f1 ( float x)
{
	return 2 * x;
}


/*
 * error1: La funcion f1 se debe declarar antes del main (linkedicion)
 * error2: Se debe incluir al archivo getnum.h para usar getFloat (compilacion)
 * error3: Se debe crear un archivo tipo header (.h) del archivo tp4_13b.c para incluir (compilacion)
 *		   en el encabezado de este archivo.
 */
