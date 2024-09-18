#include <stdio.h>
#include <string.h>
#include <assert.h>
void elimina(char v1[], const char v2[], const char v3[]){

	int k=0;
	for(int i=0; v1[i] != '\0'; i++){

		if(v1[i] != v2[i] && v1[i] != v3[i])
			v1[k++] = v1[i];

	}
	v1[k] = '\0';


}


int main(void) {
   char s[] = "abc";
   elimina(s, "123", "cab");
   assert(strcmp(s, "abc") == 0); // No se eliminan caracteres

   elimina(s, "axc", "xbc");
   assert(strcmp(s, "") == 0);

   char t[] = "abc 123";
   elimina(t, "b", "1");
   assert(strcmp(t, "abc 123") == 0);  // No se eliminan caracteres

   elimina(t, "aaaaaaaaaaaaaaaaaaaaaa", "2222222222222222222");
   assert(strcmp(t, "bc 13") == 0);

   elimina(t, "", "");  // No se eliminan caracteres
   assert(strcmp(t, "bc 13") == 0);

   puts("OK!");
   return 0;
}





