#include <stdio.h>
#include "../../Lib/getnum.h"
#include "../../lib/random.h"
#include <stdlib.h>
#include <string.h>

#define X 5




int elegirNivel(){

  int level;

  do{
    level = getint("Ingrese el nivel a Jugar: ");
  }while(level < 1 || level > 10);

  return level;

}

void generarAleatorio(int icognita[]){

  int aux[] = {1,2,3,4,5,6,7,8,9};

  int cambio, al;

  for (int i=0; i<X; i++){

    al = randInt(i+1,9);

    cambio = aux[i];

    aux[i] = aux[al];

    aux[al] = cambio;

    icognita[i] = aux[i];

  }

}

int coincideNumero(int icognita[], int num[]){

  int bien = cantidadBien(icognita, num);

  int regular = cantidadRegular(icognita, num);

  printf("\n%d bien, %d regular\n", bien, regular);

  if (bien == X)
    return 1;

  return 0;

}

int cantidadRegular(int icognita[], int num[]){

  int i, j, cont=0;

  for(i=0; i<X; i++){

    for (j=0; j<X; j++){

      if (num[i] == icognita[j] && i!=j )
        cont++;

    }

  }

  return cont;

}


int cantidadBien(int icognita[], int num[]){

  int i, cont=0;

  for(i=0; i<X; i++){

    if (icognita[i] == num[i])
      cont++;

  }

  return cont;

}




void leerNumero(int * num){

  int aux[9] = {0};

  int i=1, cont=0;



  printf("Ingrese un numero de %d digitos: ", X);

  while(i){


    scanf("%5[1-9]", num);

    if (strlen(num) == X || !estaRepetido(num))
      i=0;
    else
      printf("Vuelva a ingresar un numero de %d digitos: ", X);

  }

}

int estaRepetido(int num[]){

  int cont=0;

  for (int i=0; num[i]; i++)
    for (int j=0; j<X; j++)
      if (num[i] == num[j])
        cont++;


  return cont > 1 ? 1: 0;


}

int main() {
  randomize();

  int icognita[X];

  generarAleatorio(icognita);

  for (int i=0; i<X; i++)
    printf("%d", icognita[i]);

  puts("");

  int level = elegirNivel();


  for (int i=0; i<level; i++){

    char num[X+1];

    leerNumero(num);

    for (int j=0; j<X; j++)
      printf("%d", num[j]);


    if (coincideNumero(icognita, num)){
      puts("Ganaste!");
      return 0;
    }else{

      puts("Intento fallido");

    }

  }

  return 0;
}