#include <stdio.h>
//NO ESTA TERMINADO

//Esta funcion recibe un numero (en lo posible en hexa) y la posicion de el primer numero de un par que se quiere obtener y devuelve el par
//ej: (0110 0011, 1) devuelve 11//////(0110 0011, 3) devuelve 00 ///////(0110 0011, 5) devuelve 10////// (0110 0011, 7) devuelve 01 //////

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
    printf("\n");
    ip = (ip<<bitsNet) ;
    for (int i = 0; 24>=i; i+=8 ) {
        printf("%d.", decalaje(ip, i+1));
    }



}

int main() {
    wiFi(0xC0A80064 , 16);
}




//0001 0000 1111 1111 0001 0001 0001 0010

// 0001 0001 0001 0010 ???? ???? ???? ????
//
//
//
//
