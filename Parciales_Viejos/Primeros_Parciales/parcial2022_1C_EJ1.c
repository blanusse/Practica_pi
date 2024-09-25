#include <stdio.h>
#define COLS	5

void difDeFilas(const int v1[], const int v2[], int res[]){
	int i =0, j=0,k=0;
	for(; v1[i] != -1 && v2[j] != -1;){

		if(v1[i] < v2[j]){
			res[k++] = v1[i];
			i++;
		}
		else if(v1[i] > v2[j]){
			res[k++] = v2[j];
			j++;
		}
		else {
			j++;
			i++;
		}
	}
	while(v1[i] != -1){
		res[k++] = v1[i];
		i++;
	}
	while(v2[j] != -1){
		res[k++] = v2[j];
		j++;
	}
	res[k] = -1;

}





void difSimetrica(const int m1[][COLS], const int m2[][COLS], int res[][COLS], int filas){

	for(int i=0; i<filas; i++){
		difDeFilas(m1[i], m2[i], res[i]);
	}

}




int main(){
	int filas = 6;
	int m1[6][COLS] = {{1, 2, 3, 4, -1}, {3, 4, 5, -1}, {10, 15, 20, -1}, {-1}, {-1}, {5, 6, 7, -1}};
	int m2[6][COLS] = {{3, 4, 5, 6, -1}, {3, 4, 5, -1}, {10, 20, -1}, {1, 2, 3, 4, -1}, {-1}, {1, 2, 7, -1}};
	int res[6][COLS];


	difSimetrica(m1, m2, res, filas);
	for(int i=0; i<filas; i++){
		for(int k=0; res[i][k] != -1; k++){

			printf("%d ", res[i][k]);
		}
		printf("\n");


}

}
