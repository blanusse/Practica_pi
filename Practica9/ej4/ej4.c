#include <stdio.h>

int esPar(unsigned n);
int esImpar(unsigned n);

int 
esPar(unsigned n)
{
	return ! esImpar(n);
}

int 
esImpar(unsigned n)
{
	return ! esPar(n);
}



int main() {
	printf("%d", esPar(3));
}
//Entra en un bucle infinito