#include <stdio.h>
#include <ctype.h>
#define COLS	5
#define FILS	3
#define LETTERS 'Z' - 'A' +1

void checkRow(const char word[], const char attemp[COLS],char result[][COLS], const int numAttemp){
	int aux[LETTERS] = {0};
//Hace una matriz de apariciones de la palabra correcta
	for(int k=0; k<COLS; k++){
		int numLetter = toupper(word[k]) - 'A';
		aux[numLetter]++;
	}
//Se fija el intento elegido 
	for(int i=0; i<COLS; i++){
		if(toupper(attemp[i]) == toupper(word[i]))
			result[numAttemp][i] = 'V';
		else if(aux[toupper(attemp[i]) - 'A'] > 0)
			result[numAttemp][i] = 'A';
		else result[numAttemp][i] = 'G';
	}

}



int wordle(const char word[COLS], const char attemps[FILS][COLS], const int numAttemps, char result[][COLS]){
	int correct = 0;
	int i=0;
	for(; !correct && i<numAttemps; i++){

		checkRow(word, attemps[i], result, i);
		int fail = 0;
		for(int k=0; k<COLS && !fail; k++){
			if(result[i][k] != 'V')
				fail = 1;
		}
		if(!fail)
			correct = 1;
	}	


	if (correct && i <= FILS)
		return i;
	return -1;

}




int main(){

	char word[] = "rosas";
	char attemps[][COLS] = {{"FAROL"},{"SACOS"}, {"RATOS"}, {"ROSAS"}, {"COSAS"}, {"TECLA"}};
	int num = 6;
	char result[num][COLS];

	int respuesta = wordle(word, attemps, num, result);
	printf("%d\n", respuesta);
	
	for(int i=0; i<respuesta; i++){

		for(int k=0; k<COLS; k++){

			printf("%c ", result[i][k]);
		}
		printf("\n");

	}

}
