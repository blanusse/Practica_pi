#include <assert.h>
#include <stdio.h>
#include <ctype.h>
#define LETTERS		'Z' - 'A' + 1

int queContiene(const char a[], const char b[]){
	int count = 0, numLetter;
	int aux[LETTERS] = {0};
	for(int i=0; b[i] != '\0'; i++){

		numLetter = toupper(b[i]) - 'A';
		aux[numLetter] = 1;
	}
	for(int k=0; a[k] != '\0'; k++){
		if(isalpha(a[k])){
			numLetter = toupper(a[k]) - 'A';
			if(aux[numLetter] == 1)
				count++;
		}

	}
	return count;
}


int 
main(void) {
   int c = queContiene("Ahora me pongo a llorar", "zaMo");
   assert(c==9);    // A o a m   o  o a   o a 

   c = queContiene("Ahora me pongo a llorar", "");
   assert(c==0);    

   c = queContiene("143 I love you", "xaprarczd");
   assert(c==0);  

   c = queContiene("Mamaaa, just killed a man, put a gun...", 
       "xyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxxyxyxxyxxyM");
   assert(c==3);   // 3 veces la letra m, una vez mayúscula y 
                   // dos veces minúscula
  puts("OK!");
   return 0; 
}





