#include "museumTicketADT.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>

int
main(void) {
    // Reserva los recursos para administrar las ventas de tickets
    museumTicketADT museum = newMuseumTicket();

    // Se registra un ticket para que John visite el museo el dÃ­a 4 del aÃ±o
    assert(addTicket(museum, 4, "John") == 1);
    // Los siguientes fallan porque John ya cuenta con un ticket para el dÃ­a 4 del aÃ±o
    assert(addTicket(museum, 4, "John") == 0);
    assert(addTicket(museum, 4, "JOHN") == 0);
    assert(addTicket(museum, 4, "john") == 0);

    // Falla porque John ya cuenta con un ticket para visitar el museo el dÃ­a 4 del aÃ±o
    assert(addTicket(museum, 4, "John") == 0);
    // Se registra un ticket para que John visite el museo el dÃ­a 360 del aÃ±o
    assert(addTicket(museum, 360, "John") == 1);

    // Falla porque el dÃ­a del aÃ±o es igual a 0
    assert(addTicket(museum, 0, "Katherine") == 0);
    // Falla porque el dÃ­a del aÃ±o es mayor a 366
    assert(addTicket(museum, 367, "Katherine") == 0);

    assert(addTicket(museum, 4, "Paul") == 2);
    assert(addTicket(museum, 4, "Ariel") == 3);
    assert(addTicket(museum, 360, "Brenda") == 2);

    // Se inicializa el iterador para el dÃ­a 4 del aÃ±o
    toBeginByDay(museum, 4);
    // Quedan visitantes por recorrer para el dÃ­a 4 del aÃ±o
    assert(hasNextByDay(museum, 4) == 1);
    // Se obtiene el primer visitante para el dÃ­a 4 del aÃ±o en orden alfabÃ©tico
    assert(strcmp(nextByDay(museum, 4), "Ariel") == 0);

    toBeginByDay(museum, 360);
    // Se obtiene el primer visitante para el dÃ­a 360 del aÃ±o en orden alfabÃ©tico
    assert(hasNextByDay(museum, 360) == 1);
    assert(strcmp(nextByDay(museum, 360), "Brenda") == 0);

    assert(hasNextByDay(museum, 4) == 1);
    // Se obtiene el segundo visitante para el dÃ­a 4 del aÃ±o en orden alfabÃ©tico
    assert(strcmp(nextByDay(museum, 4), "John") == 0);
    assert(hasNextByDay(museum, 360) == 1);
    // Se obtiene el segundo visitante para el dÃ­a 360 del aÃ±o en orden alfabÃ©tico
    assert(strcmp(nextByDay(museum, 360), "John") == 0);

    assert(hasNextByDay(museum, 4) == 1);
    assert(strcmp(nextByDay(museum, 4), "Paul") == 0);
    // No quedan mÃ¡s visitantes por recorrer para el dÃ­a 4 del aÃ±o
    assert(hasNextByDay(museum, 4) == 0);
    // No quedan mÃ¡s visitantes por recorrer para el dÃ­a 360 del aÃ±o
    assert(hasNextByDay(museum, 360) == 0);

    // Se obtiene la cantidad de tickets para el dÃ­a 4 del aÃ±o
    assert(dayTickets(museum, 4) == 3);
    assert(dayTickets(museum, 360) == 2);
    assert(dayTickets(museum, 15) == 0);

    // Se obtiene la cantidad total de tickets (todos los dÃ­as del aÃ±o)
    assert(yearTickets(museum) == 5);

    // Libera los recursos utilizados para administrar las ventas de tickets
    freeMuseumTicket(museum);

    puts("OK!");
    return 0;
}