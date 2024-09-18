#include <stdio.h>

//EJ1 

void firstN(unsigned char v[], unsigned int dim, unsigned int n, int *newDim, int *deleted){
	char aux[20] = {0};
	int k=0;
	for(int i=0; i<dim; i++){
		int num = v[i];
		if(aux[num] < n){
			v[k++] = num;
			aux[num]++;
		}
		
	}
	*newDim = k;
	*deleted = dim-k;
}

void printVec(unsigned char v[], int dim ){
	for(int i=0; i<dim; i++){
		printf("%d ", v[i]);
	}
	printf("\n\n");
}


int main(){

	unsigned char v[] = {1, 2, 1, 3, 1, 4, 5, 2};
	int dim, del;
	firstN(v, 8, 3, &dim, &del); // dim es 8, del es 0, v no cambia 
	printVec(v, dim);
	firstN(v, 8, 8, &dim, &del); // dim es 8, del es 0, v no cambia 
	printVec(v, dim);

	firstN(v, 8, 4, &dim, &del); // dim es 8, del es 0, v no cambia 
	printVec(v, dim);
	firstN(v, 8, 1, &dim, &del); // dim=5, del=3, v = {1, 2, 3, 4, 5};
	printVec(v, dim);
	
	unsigned char w[] = {1, 2, 1, 3, 1, 4, 5, 2}; 
	firstN(w, 8, 0, &dim, &del); // dim=0, del=8, w = {}
	printVec(w, dim);

	unsigned char t[] = {1, 2, 1, 3, 1, 4, 5, 2};
	firstN(t, 8, 2, &dim, &del); // dim=7, del=1, t = {1, 2, 1, 3, 4, 5, 2}
	printVec(t, dim);	
return 0;

	
}



