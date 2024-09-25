#include <stdio.h>
#include <assert.h>

int checkQueenDiags(int dim, const char m[][dim], int posX, int posY){
	int error = 0;
	for(int i=1; !error &&i+posX < dim && i+posY < dim; i++){
		if(m[posX+i][posY+i] == '1')
			error = 1;
	}
	for(int i=1; !error && i+posX<dim && posY-i >= 0; i++){
		if(m[posX+i][posY-i] == '1')
			error = 1;
	}
	return !error;
}

int checkQueenRow(int dim, const char v[], int posY){
	int error = 0;
	for(int i=1; posY+i<dim; i++){
		if(v[posY+i] == '1')
			error = 1;
	}
	return !error;
}


int checkQueenCol(int dim, const char m[][dim], int posX, int posY){
	int error = 0;
	for(int i=1; posX+i < dim; i++){

		if(m[posX+i][posY] == '1')
			error = 1;
	}
	return !error;
}
	





int nQueens(int dim, const char m[][dim]){
	int count = 0;
	int error = 0;
	for(int i=0; !error && i<dim; i++){
		int foundRow = 0;
		for(int k=0; !error && !foundRow && k<dim; k++){

			if(m[i][k] == '1'){
				count++;
				if(!checkQueenDiags(dim, m, i, k))
					error = 1;
				else if(!checkQueenRow(dim, m[i], k))
					error = 1;
				else if(!checkQueenCol(dim, m, i, k))
					error = 1;
				else {
					foundRow = 1;
				}
			}	
		}
	

	}
	if(count != dim)
		error = 1;
	return !error;



}

int main(void) {
char board[][8] = {
{'0', '0', '0', '0', '1', '0', '0', '0'},
{'0', '0', '1', '0', '0', '0', '0', '0'},
{'0', '0', '0', '0', '1', '0', '0', '0'},
{'0', '0', '0', '0', '0', '0', '0', '0'},
{'0', '1', '0', '0', '0', '0', '0', '0'},
{'0', '0', '0', '0', '0', '0', '1', '0'},
{'1', '0', '0', '0', '1', '0', '0', '0'},
{'0', '0', '0', '0', '0', '0', '0', '1'},
};
// por ejemplo, hay tres reinas en la columna 4 y dos en la fila 6
assert(nQueens(8, board) == 0);

char board2[][6] = {
{'0', '0', '0', '1', '0', '0'},
{'1', '0', '0', '0', '0', '0'},
{'0', '0', '0', '0', '1', '0'},
{'0', '1', '0', '0', '0', '0'},
{'0', '0', '0', '0', '0', '1'},
{'0', '0', '1', '0', '0', '0'}
};
// Hay 6 reinas y no se atacan, retorna true
assert(nQueens(6, board2));

char board3[][6] = {
{'0', '0', '1', '0', '0', '0'},
{'1', '0', '0', '0', '0', '0'},
{'0', '1', '0', '0', '0', '0'},
{'0', '0', '0', '0', '1', '0'},
{'0', '0', '0', '0', '0', '0'},
{'0', '0', '0', '0', '0', '1'}
};
// Las reinas en (1,0) y (2,1) se amenazan en forma diagonal
assert(nQueens(6, board3) == 0);

char board4[][6] = {
{'0', '0', '0', '1', '0', '0'},
{'0', '0', '0', '0', '0', '0'},
{'0', '0', '0', '0', '1', '0'},
{'0', '1', '0', '0', '0', '0'},
{'0', '0', '0', '0', '0', '1'},
{'0', '0', '1', '0', '0', '0'}
};

// No se amenazan pero hay menos de 6 reinas
assert(nQueens(6, board4) == 0);

// No hay solución para tableros de dimensión 2 o 3
assert(nQueens(3, board2) == 0);
assert(nQueens(2, board2) == 0);

// En un tablero de 1x1 debe haber una reina

char board1[][1] = {{'1'}};
assert(nQueens(1, board1));

puts("OK!");
return 0;
}
