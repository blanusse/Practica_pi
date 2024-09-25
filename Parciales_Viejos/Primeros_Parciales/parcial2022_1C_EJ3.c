#include <stdio.h>


void secuenciaAsc (const int v[], unsigned int dim, int *length, int *start){

	if(dim != 0){
		*length = 1;
		*start = 0;
		int prevCount=0, count=0, pos =0;
		for(int i=0; i<dim; i++){
			count = 1;
			pos = i;
			for(;i<dim-1 && v[i] < v[i+1]; i++){
				count++;
			}
			if(count > *length){
				*length = count;
				*start = pos;

			}
				

	
		}

	}
	else {
		*start = 0;
		*length = 0;
	}
		


}
int main(){

	int v[] = {1, 2, 3, 4, 5, 7, 10, 90, 111};
	unsigned int dim = sizeof(v)/sizeof(v[0]);
	int *start;
	int *length;
	secuenciaAsc(v, dim, &length, &start);
	printf("%d\t%d", start, length);
	return 0;

}

