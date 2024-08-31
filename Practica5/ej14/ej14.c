#include <stdio.h>
//NO ESTA TERMINADO

//Esta funcion recibe un numero de 32 bits
//y la cantidad de digitos que queres qeu se queden (empezando desde la izquierda)

//decalaje(0111 0001 0000 1111, 4) devuelve

int decalaje (unsigned long numero, int posicion) {
    return (numero>>(posicion-1)&0xFF);
}


void wiFi (unsigned long ip, unsigned char bitsNet) {
    int contador = 0;
    printf("Red: ");
    for (int i = 0; bitsNet>i; i+=8 ) {
        printf("%d.", decalaje(ip, 25-i));
        contador++;
    }



    while (contador<4) {
        printf("0.");
        contador++;
    }
    printf("\nHost: ");
    ip = (ip<<bitsNet) ;
    for (int i = 0; 24>=i; i+=8 ) {
        printf("%d.", decalaje(ip, i+1));
    }
}

int main() {
    wiFi(0xC0A80064   , 23);
}




//0001 0000 1111 1111 0001 0001 0001 0010
//0001 0000 = 16.
//1111 1111 = 255
//000
//
//
//
//
