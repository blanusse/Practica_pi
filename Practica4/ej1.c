#include <stdio.h>
/*#define PI  3.1415

int
main(void)
{
	int a = 0;
	int b;
    b = PI + a++;
	return 0;
}


* a=1
* b=3, porque hace 3.14 + 0 y lo guarda en un  int
* */

/*
#define PI 3.14
int main(void)
{
	float a=0;
	float b;
    b = a + PI++;
    printf("%f", a);
 	return 0;
 }

 /*
 * a=0
 * b= falla al linkeditar ya que no se puede usar 3.14++, si o si es una variable
 * Lo cambiaria poniendo (PI+1). Terminaria quedando b=4.14
 * */

/*
#define CUBO(x)  x * x * x
int cubo (int num);
int
main(void)
{
	int a=4, b, c;
	b = CUBO(a+1);
	c = cubo(a+1);
	printf("%d", c);
	return 0;
}
int
cubo ( int num )
{
	return num * num * num;
}

/*
* a=4
* b= a+1*a+1*a+1 = a+a+a+1=13. si bien lo preprocesa y linkedita bien, le falta poner parentesis en la MACRO
* Lo cambiaria y pondria #define CUBO(x)  (x)*(x)*(x)
* c=125
* */

/*
#define CUBO(x)  ((x) * (x) * (x))
int cubo (int num);
int
main(void)
{
	int a=3, b, c, d, e, f;
	b = CUBO( ++a );
    c = CUBO( a++ );
    d = 3;
	e = cubo ( ++d );
	d = 3;
	f = cubo ( d++ );
	printf("%d", b);
	return 0;
}
int
cubo ( int num )
{
	return num * num * num;
}

/*
* a=9
* b= (++3) * (++4) * (++5)
* c=6*7*8 =336
* d=4
* e= 4*4*4 = 64
* f=27
* */


#define DIVISION(x, y, z)	{int i; \
				  for(z = 0, i = x-y; i >= 0; z++, i-= y); \
					}
int
main( void )
{
	int a, b, c, m, n, p, x, y, z;
	a = 20; b=5; c=3;
	DIVISION(a, b, c);
	m=5; n=4; p=2;
	DIVISION(m++, n--, p);
	x=15; y=3; z=0;
	DIVISION(x, y, 0);
    printf("%d", a);
	return 0;
}
/*
*
* */

