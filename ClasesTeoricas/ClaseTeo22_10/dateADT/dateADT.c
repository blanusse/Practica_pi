#include "../dateADT.h"

#include <stdlib.h>

struct dateCDT {
    char day, month, year;

};

dateADT newDate(unsigned char day, unsigned char month, unsigned int year) {
    dateADT toReturn = malloc(sizeof(struct dateCDT));
    toReturn->day = day;
    toReturn->month = month;
    toReturn->year = year;
    return toReturn;

}

void freeDate(dateADT date) {
    free(date);
}
