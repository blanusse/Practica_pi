#include <stdio.h>
#include <ctype.h>

int esVocal(char a){
	char letter = toupper(a);
	return (letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O'|| letter == 'U');	

}


void eliminaVocal(char v[]){
	int k=0;
	for(int i=0; v[i] != '\0'; i++){
		if (i == 0 && esVocal(v[i])){
			if(esVocal(v[i+1]))
				v[k++] = v[i];
		}
		else{
			if(!esVocal(v[i])){
				v[k++] = v[i];
			}
			else if((!isalpha(v[i+1]) && esVocal(v[i-1])) || !isalpha(v[i-1]) && esVocal(v[i+1])){
				v[k++] = v[i];
			}
			else if((esVocal(v[i+1]) && esVocal(v[i-1])) || (!isalpha(v[i-1]) && !isalpha(v[i+1])))
				v[k++] = v[i];
		}
	}
	v[k] = '\0';
}

int main(){

	char v[] = "aa ee oe ai ou";
	eliminaVocal(v);
	for(int i =0; v[i] != '\0'; i++){

		printf("%c", v[i]);
	}

}

