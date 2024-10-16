#include <stdio.h>
#include <string.h>

#define COLS	5
#define FILS	4


typedef enum {DER=0, IZQ, ABA, ARR, I_AR, I_AB, D_AR, D_AB } Tdireccion;

struct posicion {
	char * palabra;
	size_t fila;
	size_t columna;
	Tdireccion direccion;
};

int buscarPalabra(char letra, char palabras[][]) {
	for(int i=0; strcmp(palabras[i], ""); i++) {
		if(palabras[i][0] == letra) {
			return 1;
		}
	}
	return 0;
}



struct posicion *resolverSopa(char sopa[][COLS], char palabras[][] ) {
	struct posicion *respuesta = NULL;
	for(int i=0; i<FILS; i++) {
		for(int k=0; k<COLS; k++) {
			if(buscarPalabra(sopa[i][k], palabras)) {

			}
		}
	}
}