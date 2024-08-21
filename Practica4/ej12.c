
/*
a)



#include <stdio.h>
int
neg(int n)
{
	return -n;
}


int
main(void)
{
	int c = 2;
	
	c = neg(c);
	printf("%d\n",c);
	return 0;
}
Devuelve el valor esperado (-2)
*/

#include <stdio.h>
double
neg (double n){
    return -n;
}

int main(){
    double i = 5.42;
    i = neg(i);
    printf("%f\n", i);
    return 0;
}


/*Devuelve el valor esperado (-5.42)*/