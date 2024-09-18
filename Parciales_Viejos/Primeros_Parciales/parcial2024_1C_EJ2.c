#include <stdio.h>
#include <assert.h>








int checkRowAndCol(unsigned int dim, const char m[][dim], unsigned int posX, unsigned int posY){
	int error = 0, countRow = 0, countCol=0;
	for(int i=0; i<dim && !error; i++){
		if(m[posX][i] == '1'){
			countRow++;
		}

		if(m[i][posY] == '1'){
			countCol++;
		}
		
		if(countRow > 1 || countCol > 1)
			error = 1;
	}

	return !error;
}

int checkDiagonal(unsigned int dim, const char m[][dim], unsigned int posX, unsigned int posY){

	int error =0, countDiag1=0, countDiag2 = 0;
	for(int i=0, k=0;!error && i<dim && k<dim && posX-i > 0 && posY-k > 0; i++, k++){
		if(m[posX + i][posY + k] == '1'){
			countDiag1++;
		}
		if(m[posX - i][posY - k] == '1'){
			countDiag1++;
		}
		if(m[posX + i][posY - k] == '1')
			countDiag2++;
		if(m[posX - i][posY + k] == '1')
			countDiag2++;

		if(countDiag1 > 2 || countDiag2 > 2)
			error = 1;
	}
	return !error;
}


int nQueens(unsigned int dim, const char m[][dim]){
	int error = 0, count=0;
	for(int i=0; i<dim && !error; i++){
		for(int k=0; k<dim && !error; k++){

			if (m[i][k] == '1'){
	
				count++;
				if(!checkRowAndCol(dim, m, i, k))
					error = 1;
				if(!error && !checkDiagonal(dim, m, i, k))
					error = 1;
			}

		}
	}
	if(count != dim)
		error = 1;
	
	return !error;

}






int main(){

	char board[][8] = {
{'0', '0', '0', '0', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0', '0', '0', '0'}, {'0', '0', '0', '0', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0', '0', '0', '0'}, {'0', '1', '0', '0', '0', '0', '0', '0'}, {'0', '0', '0', '0', '0', '0', '1', '0'}, {'1', '0', '0', '0', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0', '0', '0', '1'},
};
assert(nQueens(8, board) == 0);


char board2[][6] = {
{'0', '0', '0', '1', '0', '0'},
{'1', '0', '0', '0', '0', '0'}, 
{'0', '0', '0', '0', '1', '0'}, 
{'0', '1', '0', '0', '0', '0'}, 
{'0', '0', '0', '0', '0', '1'}, 
{'0', '0', '1', '0', '0', '0'}
};
(nQueens(6, board2));


char board3[][6] = {
{'0', '0', '1', '0', '0', '0'},
{'1', '0', '0', '0', '0', '0'}, {'0', '1', '0', '0', '0', '0'}, {'0', '0', '0', '0', '1', '0'}, {'0', '0', '0', '0', '0', '0'}, {'0', '0', '0', '0', '0', '1'}
};
assert(nQueens(6, board3) == 0);


char board4[][6] = {
{'0', '0', '0', '1', '0', '0'},
{'0', '0', '0', '0', '0', '0'}, {'0', '0', '0', '0', '1', '0'}, {'0', '1', '0', '0', '0', '0'}, {'0', '0', '0', '0', '0', '1'}, {'0', '0', '1', '0', '0', '0'}
};
assert(nQueens(6, board4) == 0);


assert(nQueens(3, board2) == 0);
assert(nQueens(2, board2) == 0);

char board1[][1] = {{'1'}};
assert(nQueens(1, board1));
    puts("OK!");
return 0;


}
