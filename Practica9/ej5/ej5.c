#include <stdio.h>

int esImpar(unsigned n);
int esPar(unsigned n);


int 
esPar(unsigned n)
{
    if (n == 0)
        return 1;

        return esImpar(n-1);
}

int 
esImpar(unsigned n)
{
    if (n == 1)
        return 1;

        return esPar(n-1);
}

int main() {
    printf("%d", esPar(5));
}

// Va a funcionar solo cuando si ingresa un valor que la funcion devuelva 1.
// Entra en un bucle pq cuando n= 1 esta en esPar que chequea si n=0.
// Despues pasa a esImpar con n=0 que chequea si n=1. Entonces dsp sigue 
