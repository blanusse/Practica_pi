#ifndef TEORICAS_C_DATE_H
#define TEORICAS_C_DATE_H


typedef struct dateCDT * dateADT;

dateADT newDate(unsigned char day, unsigned char month, unsigned int year);

void freeDate(dateADT date);

int setDay(dateADT date, int day);

void dateToString(const dateADT date, char s[]);

#endif
