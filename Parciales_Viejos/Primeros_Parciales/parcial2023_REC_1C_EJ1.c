#include <stdio.h>



void ordena(unsigned int v[]){
	if (v[0] != -1){
		int k=0;
		for(int i=1; v[i] != -1; i++){
			if(v[i] > v[k]){
				k++;
				v[k] = v[i];
			}
		}
		v[++k] = -1;
	}
	else
		v[0] = -1;
}



int main(){

	unsigned int v[] = {10, 10, 4, 8, 9, 7, 8, 6, -1};
	ordena(v);
	for(int i=0; v[i] != -1; i++)
		printf("%d\t", v[i]);

}
