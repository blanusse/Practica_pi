#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#define ABC	26
#define COLS	4

 



int isWordLadder(unsigned int dim, unsigned int length, char m[][length]){
	int error = 0, posCambio1, posCambio2;
	for(int i=1; i<dim && !error; i++){
		int cambio=0;
		for(int k=0; k<length && !error; k++){

			if(toupper(m[i][k]) != toupper(m[i-1][k])){
				cambio++;
				posCambio1 = k;
					
			}
			if (cambio > 1)
				error = 1;
		}
		cambio = 0;
		i++;
		for(int j=0; j<length && !error; j++){

			if(toupper(m[i][j]) != toupper(m[i-1][j])){
				cambio++;
				posCambio2 = j;
			}
			if (cambio > 1)
				error = 1;
		}
		if(posCambio1 == posCambio2)
			error = 1;
	}
	return !error;
}








int main(void) {
    char wordMatrix[][COLS] = {
            {'T', 'e', 'S', 't'},
            {'b', 'e', 'S', 'T'},
            {'B', 'E', 's', 'o'},
            {'B', 'E', 'S', 'A'}};
assert(!isWordLadder(4, 4, wordMatrix));

assert(isWordLadder(1, 4, wordMatrix) == 1);

assert(isWordLadder(3, 4, wordMatrix) == 1);
    char wordMatrix2[][3] = {
            {'T', 'e', 'S'},
            {'t', 'b', 'e'},
            {'S', 'b', 'E'},
            {'B', 'b', 'e'}};

assert(!isWordLadder(4, 3, wordMatrix2));
    char wordMatrix3[][3] = {
            {'a', 'm', 'o'},
            {'a', 'r', 'o'},
	{'o', 's', 'a'}};
	assert(!isWordLadder(3, 3, wordMatrix3)); 
	puts("OK!");
return 0;
}
