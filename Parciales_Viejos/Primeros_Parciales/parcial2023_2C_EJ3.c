#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#define LETTERS		'Z'-'A' + 1

void palabraAparicion(const char a[], int aux[]){
	
	for(int i=0; a[i] != '\0'; i++){
		if(isalpha(a[i])){
			int num = toupper(a[i]) - 'A';
			aux[num]++;
		}
	}



}

int anagrama (const char a[], const char b[]){
	int error =0;
	int aux1[LETTERS] = {0};
	int aux2[LETTERS] = {0};
	palabraAparicion(a, aux1);
	palabraAparicion(b, aux2);
	for(int i=0;!error && i<LETTERS; i++){
		if(aux1[i] != aux2[i])
			error = 1;
	}
	return !error;
	


}





int main(){

char * s = "anagrama";
assert(anagrama(s, "amar gana")); 
assert(anagrama("enrique", "quieren")); 
assert(anagrama(s, s));
assert(anagrama(" ", "")); 
assert(anagrama("amar gana", s)); 
assert(anagrama("", ""));
assert(anagrama("a gentleman", "elegant man"));
assert(anagrama("a", "") == 0); 
assert(anagrama("mar", "amar") == 0);
puts("OK!");

}






