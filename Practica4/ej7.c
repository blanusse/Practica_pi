#include <stdio.h>
# define ISDIGIT(x) (x) >= '0' && (x) <= '9'

int main(void) {
    int letra;
	letra = getchar();
	if (ISDIGIT(letra) )
		printf("Es un dígito\n");
}