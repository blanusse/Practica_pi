
/*
A)

for ( i = 46; i <= 'H'; i++)
{
      printf("%d %c %c\t", i, i, tolower(i)); // valor ASCII de "i" - letra que corresponde a "i" en ASCII - minusculas de las letras que corresponden a "i" en ASCII
      printf("%s ", isalnum(i)? "si" : "no"); // si el valor de "i" en ASCII es un numero o letra imprime si, sino no
      printf("%s ", isalpha(i)? "si" : "no"); //si el valor de "i" en ASCII es una letra imprime si, sino no
      printf("%s ", isdigit(i)? "si" : "no");//si el valor de "i" en ASCII es un numero imprime si, sino no
      printf("%s ", islower(i)? "si" : "no");//si el valor de "i" en ASCII es minuscula imprime si, sino no
      printf("%s ", isupper(i)? "si" : "no");//si el valor de "i" en ASCII es mayuscula imprime si, sino no
      printf("%s ", isxdigit(i)? "si" : "no");//
      printf("%s ", iscntrl(i)? "si" : "no");// si el valor de "i" en ASCII es un caracter de control imprime si, sino no
      printf("%s \n", ispunct(i)? "si" : "no");//si el valor de "i" en ASCII es un numero imprime si, sino no
}

-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
B)
*/


for ( x = -1; x < 2; x += 0.5 )
{
	printf("%f  %f   %f   %f\n", x, fabs(x), ceil(x), floor(x)); // imprime a x - imprime el valor absoluto de c - redondea para arriba a - redondea para abajo a x
	printf("%f  %f\n", pow(x,2), pow(x,.5));// hace x al cuadrado - hace x a la 1/5
}


