#include "museumTicketADT.h"

#include <assert.h>
#include <string.h>
#include <strings.h>
#define DAYS 366

struct ticketOwner {
    char *name;
    struct ticketOwner *next;
};

typedef struct ticketOwner *ownerList;

typedef struct museumDay {
    size_t ticketCount;
    ownerList firstOwner;
    ownerList currentOwner;
}museumDay;


struct museumTicketCDT {
    museumDay year[DAYS];
    size_t yearTickets;
};
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------


museumTicketADT newMuseumTicket(void) {
    return calloc(1, sizeof(struct museumTicketCDT));
}

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

static ownerList addTicketRec(ownerList owners,  char * visitor, int *flag) {
    int c;
    if( owners == NULL || (c = strcasecmp(visitor, owners->name)) < 0) { // encontro el lugar para poner
        ownerList newOwner = malloc(sizeof(struct ticketOwner));
        newOwner->name = malloc(sizeof(char) * (strlen(visitor) + 1));
        strcpy(newOwner->name, visitor);
        newOwner->next = owners;
        *flag = 1;
        return newOwner;
    }
    if(c == 0) {
        *flag = 0;
        return owners;
    }
    owners->next = addTicketRec(owners->next, visitor, flag);
    return owners;
}

int addTicket(museumTicketADT museumTicketADT, size_t dayOfYear,  char * visitor) {
    if(dayOfYear <= 0 || dayOfYear > 366)
        return 0;
    int flag = 0;
    museumTicketADT->year[dayOfYear-1].firstOwner = addTicketRec(museumTicketADT->year[dayOfYear-1].firstOwner, visitor, &flag);
    museumTicketADT->year[dayOfYear-1].ticketCount+=flag;
    museumTicketADT->yearTickets+=flag;
    if(flag == 0)// si no se agrego nada pq ya estaba ese nombre, devuelve 0
        return 0;
    return museumTicketADT->year[dayOfYear-1].ticketCount; //devuelve la cantidad de tickets en el dia
}


//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

int dayTickets(const museumTicketADT museumTicketADT, size_t dayOfYear) {
    if(dayOfYear <= 0 || dayOfYear >366) {
        return -1;
    }
    return museumTicketADT->year[dayOfYear-1].ticketCount;
}

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------


int yearTickets(const museumTicketADT museumTicketADT) {
    return museumTicketADT->yearTickets;
}


//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

void toBeginByDay(museumTicketADT museumTicketADT, size_t dayOfYear) {
    museumTicketADT->year[dayOfYear-1].currentOwner = museumTicketADT->year[dayOfYear-1].firstOwner;
}


//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

size_t hasNextByDay(museumTicketADT museumTicketADT, size_t dayOfYear) {
    return museumTicketADT->year[dayOfYear-1].currentOwner != NULL;
}


//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

char * nextByDay(museumTicketADT museumTicketADT, size_t dayOfYear) {
    assert(hasNextByDay(museumTicketADT, dayOfYear));
    char *toReturn = museumTicketADT->year[dayOfYear-1].currentOwner->name;
    // int tam = strlen(museumTicketADT->year[dayOfYear-1].currentOwner->name);
    // char *toReturn = malloc(sizeof(char) *(tam+1));
    // strcpy(toReturn, museumTicketADT->year[dayOfYear-1].currentOwner->name);
    museumTicketADT->year[dayOfYear-1].currentOwner = museumTicketADT->year[dayOfYear-1].currentOwner->next;
    return toReturn;
}

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

void freeMuseumTicketRec(ownerList owners) {
    if(owners == NULL)
        return;
    ownerList aux = owners->next;
    free(owners->name);
    free(owners);
    freeMuseumTicketRec(aux);
}

void freeMuseumTicket(museumTicketADT museumTicketADT) {
    for(int i=0; i<DAYS; i++) {
        freeMuseumTicketRec(museumTicketADT->year[i].firstOwner);
    }
    free(museumTicketADT);
}