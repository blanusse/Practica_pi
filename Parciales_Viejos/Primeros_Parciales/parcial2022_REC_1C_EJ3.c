#include <stdio.h>
#define N	3
#define validNum(a)	((a) >= 1 && (a) <= N*N)



int esMagica (const int m[][N]){
	int error = 0;
	int aux[N*N] = {0};
	int sumAnt=0;
	for(int i=0; !error && i<N; i++){
		int sumaF = 0, sumaC = 0;
		for(int k=0;!error && k<N; k++){
			int num = m[i][k] - 1;
			if(aux[num] == 1 || !validNum(m[i][k]))
				error = 1;
			else {
				aux[num] = 1;
				sumaF += m[i][k];
				sumaC += m[k][i];
			}
		}
		if(i > 0 &&(sumaF != sumaC || sumaF != sumAnt || sumaC != sumAnt))
			error = 1;
		else{
			sumAnt = sumaF;
		}	
	}
	return !error;


}


int main(){

	//int v[][N] = {{16, 3, 2, 13}, {5, 10, 11, 8}, {9, 6, 7, 12}, {4, 15, 14,1}};
	//int v2[][N] = {{16, 4, 5, 10}, {11, 2, 3, 6}, {12, 9, 13, 15}, {7, 8, 1, 14}};
	int v3[][N] = {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};
	int v4[][N] = {{4, 9, 2}, {4, 5, 6}, {7, 1, 7}};
	


	printf("%d\n%d", esMagica(v3), esMagica(v4));
	return 0;


}






