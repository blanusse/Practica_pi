#include <stdio.h>
#include <assert.h>
#include <ctype.h>

/*
int aparece(const int vec[], int num, unsigned dim){
	int  esta =0;
	for(int i=0; i<dim && !esta; i++){

		if (vec[i] == num)
			esta = 1;
	}
	return esta;
}
*/

int aparece2( int v[], int num, unsigned dim){
	
	int esta = 0;
	int *actual = v; /*Puntero que apunta a la primera direccion de memoria del vecto*/ 
	int *final = actual+dim; /* Puntero que apunta a la ultima direccion de memoria del vector*/
	
	while( actual < final && !esta){
		if (*actual == num)
			esta = 1;
		actual++;
	}
	return esta;

}




int longString ( const char vec[]){
	int count = 0;
	char *punt = vec;
	while (*punt != '\0'){

		if (isalnum(*punt)){
			count++;
		}
		punt++;	

	}
	return count;
}









int main(){
	
	assert (longString("Hola")==4);
	assert (longString("Abc")==3);
	assert (longString("") == 0);
	printf("OK!");
	return 0;
}

