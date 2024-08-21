a)
void
f1 (void) 
{
printf ("Dentro de la función f1\n");

 	void
 	f2(void) 
{
 		printf ("Dentro de f2\n");
 	}
}

/* Nose*/
b)
int
suma (int x, int y)
{
int respuesta;	
respuesta = x + y;
}

/*  el int respuesta hay que declararlo en los () además le falta el return respuesta */

c)
int
suma (int n);
{
	if (n<=0)
		return 0;
	else
		n + 1;
}
/*  en el else, n+1 no se guarda, debería ser ++n y dsp agregar el return n */

 
d)
void
f2( float a )
{
float a;
printf ("%f\n",a*a);
}
/*  no hace falta declarer float a adentro de la function.  */


e)

void
f3 ( int letra )
{
	printf('Letra: ');
	putchar(letra);
	putchar("\n");
}
/*Todo en un printf(“Letra: %c \n”, letra)*/
