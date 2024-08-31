#define N 10
#define M 20

int
main (void)
{
	int dim = 7; // Crea una variable simple con el 7
	int vectorA[ M * N]; // Crea un arreglo de 200 espacios
	int vectorB[ -10 ]; // Error1: no se pueden hacer arreglos de un numero negativo
	int vectorC[ 10.0 ]; // Error2: iene que ser un int
	int vectorD[dim]; // Crea un arreglo de 7 espacios
	vectorC[2.5] = 'a'; // Error3: Quiere acceder a un espacio que no existe en el arregloC. Ademas el vectorC no existe
	vectorB[-1] = 5;// Error4: Quiere acceder a un espacio anterior de la memoria, ademas el vectorB no se pudo crear
	vectorA['0'] = 10;// cambia el casillero numero 48 por 10
	vectorC[vectorA[48]] = 5.5;//Error5: No se creo el vector C, entonces no se puede acceder al lugar 10
	vectorA[1000] = 0;//no existe el casillero 1000, pero no falla al compilar
	vectorA[M * N] = 10;//Error7: no se puede, quiere cambiar el casillero 200 pero el vector va desde el 0-199
	return 0;
}
