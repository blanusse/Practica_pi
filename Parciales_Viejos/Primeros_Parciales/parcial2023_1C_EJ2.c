#include <stdio.h>
#define N	6
#define VALID_NUM(a)	((a) > 0 && (a) <= 3*N)
#define NUMS	3*N

int checkBlock (const int v[][N], int dirX, int dirY){
	int sum = 0;
	int aux[NUMS + 1] = {0};
	int error = 0;
	for(int i=0; !error && i<3; i++){

		for(int k=0;!error && k<3; k++){
			int cell = v[dirX + i][dirY + k];
			if(!VALID_NUM(cell))
				error = 1;
			else if (aux[cell] == 1)
				error = 1;
			else{
				sum += cell;
				aux[cell] = 1;
			}
		}
	}
	if(error)
		return 0;
	return sum;
}







int verifica (const int v[][N]){

	int error =0;
	int prevSum = 0;
	for(int i=0; i<N; i+= 3){

		for(int k=0; k<N; k += 3){

			int sumBlock = checkBlock(v, i, k);
			if(sumBlock == 0)
				error = 1;
			else{
				if(sumBlock != prevSum && !(k == 0 && i == 0))
					error = 1;
				else
					prevSum = sumBlock;
			}
		}


	}
	return !error;

}



int main(){

	//int v[][N] = {{1, 3, 2}, {9, 8, 6}, {4, 7, 5}};
	//printf("%d", verifica(v));
	
	int v2[][N] = {{1, 3, 2, 3, 8, 5}, {9, 8, 6, 6, 2, 4}, {4, 7, 5, 5, 9, 3}, {2, 9, 6, 1, 4, 5}, {5, 1, 3, 7, 2, 8}, {8, 4, 7, 3, 6, 9}};
	printf("%d", verifica(v2));


}
