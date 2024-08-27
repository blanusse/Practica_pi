/*
A)

#include <stdio.h>

int a,b; 
void local ( void );             

int
main ( void ){
    a = 2; b = 3;
    local();
 	printf(" a vale : %d\tb vale %d\n",  a, b );
    return 0;
}

void
local ( void )
{
int a;
    a =  -5;
    b = 10;
 	return ;
}

// No hay errores, el main se ejecuta bien pero la funcion no puede cambiar los valores de a y b
*/
/*
-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

B)
#include <stdio.h>
int a, b, c;

void primero ( void );
void segundo ( void );

int
main ( void )
{
    a = 1;
 	printf("El valor de c es %d\n", c );
    segundo();
    printf ("El valor de a es %d, el de b es %d\n",a , b );
  	primero();
    printf("El valor de a es %d, el de c es %d\n", a, c );
	return 0;
}

void
primero ( void ){
    int a ;
 	a = 3;
 	c = 0;
}

void
segundo ( void ){
	int a ;
	c = 0;
	a = 2;
	b = -a;
}


//Deberia haber un \n al final de printf
//Cuando se invoca a segundo(), solo  cambia el valor de b pero el de a, no
//Cuando se invoca a primero(), no se cambia el valor de a
*/

/*
-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
C)
#include <stdio.h>

char letra;
void segundo ( void );

int
main( void ){
     printf( "Ingrese un carácter : ");
     letra = getchar();
     segundo();
     printf( "letra es : %c\n", letra );
     return 0;
}

void
segundo( void ){
    char letra;
 	letra = 'X';
 	return;
}

// Falta cerrar la funcion segundo con }
// El codigo dentro de la funcion no cambia la variable letra ya que
// trabaja con copias de las variables

*/
/*
-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

D)
#include <stdio.h>

static int  m;
int b;
static void este(void);

int
main(void)
{
      m = 2;
      b = 3;
 	  este();
      printf("m vale : %d\n", m );
      printf("b vale : %d", b );
 	  return 0;
}

static void este(void){
    static int m;
 	m++;
    b = - 3;
    printf( "Dentro de este() m vale %d y b vale %d\n", m, b);
 	return;
}

//Faltaba el ; dsp de declarar int m al principio
//Faltaba el \n despues de el printf dentro de este() y despues de b vale...
//Como se declara static int m en este(), imprime el valor que se le da (0 + 1)
//Luego se le cambia el valor a b=3 que termina como b=-3, se queda ese valor e imprime eso
// Cuando sale de este() m sigue valiendo 2 y b vale -3
*/

#include <stdio.h>

static int cubo(int num);
int
main( void ){
    int x;
 	for ( x=1; x<=5; x++)
		printf("El cubo de %d es %4d\n", x, cubo(x));
	return 0;
}

static int
cubo(int num){
	return num * num * num;
}

//No hay errores, calcula el cubo perfectamente