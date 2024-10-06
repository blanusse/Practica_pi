#include <stdio.h>
#include <ctype.h>


char *
aMayusculas( char * s)
{
	char * t;
	for ( t = s; *t = toupper(*t); t++)
		;

	return s;
}

int main() {

	int v[] = {1,2,3,0};
	printf( "%s\n", aMayusculas(v + 1));
	printf( "%s\n", v);
	//No imprime nada, %s es para chars y se declara como int, ademas se le pasa a la funcion int cdo pide chars

	// char * p = "Hola mundo";

	//printf ("%s\n", aMayusculas(p));
	//Segmentation fault

	// printf ("%s\n", p);
	//la mundo

	char p[] = "Hola mundo";

	printf ("%s\n", aMayusculas(p) + 2);


	printf ("%s\n", p);
	//HOLA MUNDO


}