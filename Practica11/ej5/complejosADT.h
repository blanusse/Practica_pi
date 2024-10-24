
#ifndef COMPLEJOSADT_H
#define COMPLEJOSADT_H

typedef struct complejosCDT * complejosADT;

//Crea un numero complejo
complejosADT newComplex(double real, double imaginary);

//Devuelve la parte real del numero complejo
double getReal(complejosADT num);

//Devuelve la parte imaginaria del numero complejo
double getImaginary(complejosADT num);

//Suma dos numeros complejos
complejosADT sumComp(complejosADT num1, complejosADT num2);

complejosADT restaComp(complejosADT num1, complejosADT num2);

complejosADT divideComp(complejosADT num1, complejosADT num2);

complejosADT multComp(complejosADT num1, complejosADT num2);

complejosADT conjComp(complejosADT num);

void freeComp(complejosADT num);



#endif //COMPLEJOSADT_H
