#include <stdio.h>
/*

int
mcd (int a, int b)
{
	int auxi ;
	while (auxi>0)
	{
		a = b;
        b = auxi;
        auxi = a % b ;

}
	return a;
}

int main() {
    return mcd(9,3);
}


* error1: el auxi = a % b deberia ir el la primer linea del while
* error2: cuando se declara auxi, se recomienda poner auxi = a % b ya que en auxi se
* guarda basura y nada asegura que sea mayor a cero, y en caso de ser cero no entra al while
*
* Codigo corregido:
*
*/
int
mcd (int a, int b)
{
    int auxi = a % b ;
    while (auxi>0)
    {
       auxi = a % b ;
       a = b;
       b = auxi;
}
    return a;
}



