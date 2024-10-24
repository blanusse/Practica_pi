#include "complejosADT.h"
#include <stdlib.h>

struct complejosCDT {
    double realPart;
    double imaginaryPart;
};

complejosADT newComplex(double real, double imaginary) {
    complejosADT toReturn = malloc(sizeof(struct complejosCDT));
    toReturn->imaginaryPart = imaginary;
    toReturn->realPart = real;
    return toReturn;

}

double getReal(complejosADT num) {
    return num->realPart;
}

double getImaginary(complejosADT num) {
    return num->imaginaryPart;
}

complejosADT sumComp(complejosADT num1, complejosADT num2) {
    complejosADT toReturn = malloc(sizeof(struct complejosCDT));
    toReturn->imaginaryPart = num1->imaginaryPart + num2->imaginaryPart;
    toReturn->realPart = num1->realPart + num2->realPart;
    return toReturn;
}


complejosADT restaComp(complejosADT num1, complejosADT num2) {
    complejosADT toReturn = malloc(sizeof(struct complejosCDT));
    toReturn->imaginaryPart = num1->imaginaryPart - num2->imaginaryPart;
    toReturn->realPart = num1->realPart - num2->realPart;
    return toReturn;
}

complejosADT multComp(complejosADT num1, complejosADT num2) {
    complejosADT toReturn = malloc(sizeof(struct complejosCDT));
    toReturn->imaginaryPart = (num1->realPart * num2->imaginaryPart) + (num1->realPart * num2->imaginaryPart);
    toReturn->realPart = (num1->realPart * num2->realPart) - (num1->imaginaryPart * num2->imaginaryPart);
    return toReturn;
}

complejosADT divideComp(complejosADT num1, complejosADT num2) {
    complejosADT toReturn = malloc(sizeof(struct complejosCDT));
    double aux = num2->realPart * num2->realPart + num2->imaginaryPart * num2->imaginaryPart;
    toReturn->imaginaryPart = (num1->imaginaryPart * num2->realPart - num1->realPart * num2->imaginaryPart)/aux;
    toReturn->realPart = (num1->realPart * num2->realPart + num1->imaginaryPart * num2->imaginaryPart)/aux;
}

complejosADT conjComp(complejosADT num) {
    complejosADT toReturn = malloc(sizeof(struct complejosCDT));
    toReturn->realPart = num->realPart;
    toReturn->imaginaryPart = -num->imaginaryPart;
    return toReturn;
}

void freeComp(complejosADT num) {
    free(num);
}

