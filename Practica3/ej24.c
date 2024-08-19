#include <stdio.h>

int 
main(void)
{
    float a = 0.1;

    if (a == 0.1)
        printf("SON iguales\n");
    else
        printf("NO SON iguales: a vale %g que no es igual a 0.1\n",a);

    return 0;
}
