#include <stdio.h>
#define M	2

int sumBorde(const int m[][M], int dirX, int dirY){
	int suma = 0;
	for(int i=dirY; i < M-dirY; i++){

		suma += m[dirX][i];
		suma += m[M-dirX-1][i];
	}
	for(int k = dirX+1; k< M-dirX-1; k++){

		suma += m[k][dirY];
		suma += m[k][M-dirY-1];
	}
	return suma;

}




void bordes(const int m[][M], int *v){

	for(int i=0, k=0; i<M/2 || k<M/2; i++, k++){

		v[i] = sumBorde(m, i, k);
	}
}


int main() {
//	int m[][M] = {{1, 1, 1, 1, 1, 1},
//{1, 2, 2, 2, 2, 1},
//{1, 2, 3, 3, 2, 1},
//{1, 2, 3, 3, 2, 1},
//{1, 2, 2, 2, 2, 1},
//{1, 1, 1, 1, 1, 1}
//	};
	int m2[][2] = {{1, 3}, {3, 3}
};

int v[M/2] = {0};
bordes(m2, &v);
	for(int i=0; i<M/2; i++ )
		printf("%d\t", v[i]);

}



