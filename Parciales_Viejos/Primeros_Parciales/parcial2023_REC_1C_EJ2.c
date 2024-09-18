#include <stdio.h>
#define N	4

int containedRows(const int v1[], const int v2[]){
	int error = 0;
	for(int i=0; !error && i<N; i++){
		int found = 0;
		for(int k=0;!found && k<N; k++){
			if(v1[i] == v2[k])
				found = 1;
		}
		if(!found)
			error = 1;
	}
	return !error;

}


int AcontainedInB(const int a[][N], const int b[][N]){
	int error = 0;
	for(int i=0; !error && i<N; i++){
		int found = 0;
		for(int k=0;!found &&  k<N; k++){
		
			found = containedRows(a[i], b[k]);	
		}
		if(!found)
			error = 1;
	}
	return !error;

}



int contieneFilas(const int a[][N], const int b[][N]){

	
	if(AcontainedInB(a, b))
		return 1;
	else if (AcontainedInB(b, a))
		return 2;
	return 0;

}



int main(){

	int a[][N] = {{1, 1, 2, 3}, {3, 3, 3, 3}, {9, 8, 1, 2}, {1, 8, 1, 8}};
	int b[][N] = {{1, 8, 9, 2}, {1, 3, 2, 4}, {7, 7, 7, 7}, {4, 5, 65, 7}};
	
	printf("%d\n" ,contieneFilas(b, a));
	return 0;



}



