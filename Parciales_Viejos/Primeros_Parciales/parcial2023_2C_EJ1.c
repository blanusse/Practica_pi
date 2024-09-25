#include <stdio.h>
#define COLS	6


int esCapicua(const char v[]){
	int error = 0;
	for(int i=0; i<COLS/2; i++){
		if(v[i] != v[COLS-1-i]){
			error = 1;
		}
	}
	return !error;

}

void pasteRow(char v[], char v2[]){

	for(int i=0; i<COLS; i++){
		v2[i] = v[i];
	}
}


int elimina(char m[][COLS], int rows){
	int k=0;
	for(int i=0; i<rows; i++){

		if(!esCapicua(m[i])){
			pasteRow(m[i], m[k++]);
		}
	}

	return k; 

}





int main(){

	char mat[][COLS] = {"L#BB#L", "31rR13", "111111", "LsdDss"};
	int rows = 4;
	int dim = elimina(mat, rows);

	for(int i=0; i<dim; i++){

		for(int k=0; k<COLS; k++){
			printf("%c", mat[i][k]);
		}
		printf("\n");


}


}
