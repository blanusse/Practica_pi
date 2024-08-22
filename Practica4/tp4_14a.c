#include <stdio.h>

float f1 (float);
float funAuxiliar (float);

int
main (void)
{
	float x, y, z;
	x= getfloat("Ingrese un n�mero real :");
	putchar('\n');

	y = f1(x);
	z = f2(x);

	printf("El doble absoluto de %g es %g\n",x, y);
	printf("El triple absoluto de %g es %g\n",x , z);
	return 0;
}

float
f1 ( float x)
{
	return 2 * funAuxiliar(x);
}

float
funAuxiliar (float x)
{
	if ( x < 0 )
		x = -x;

	return x;
}

/*
 * error1: En vez de copiar las funciones del otro archivo,
 *		   es conveniente incluirlo en el encabezado con su archivo .h
 * error2: Le falta incluir a getnum.h para usar getfloat
 * error3: no deja usar f2 poruqe no esta incluido el archivo que contiene la funcion, ademas de no invocarla arriba
 * error4: Falta hacer el archivo .h del otro
 */