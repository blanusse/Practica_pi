#include <stdlib.h>

typedef struct museumTicketCDT * museumTicketADT;

/**
 * Reserva los recursos para administrar las ventas de tickets para visitar un museo en un aÃ±o determinado
 * Nota: Como no se indica el aÃ±o para el que se lo utilizarÃ¡ se asume que el aÃ±o serÃ¡ siempre bisiesto
 */
museumTicketADT newMuseumTicket(void);

/**
 * Se registra un ticket para que #visitor visite el museo el dÃ­a #dayOfYear del aÃ±o
 * Retorna la cantidad actual de tickets registrados para visitar el museo ese dÃ­a
 * Retorna 0 si #dayOfYear es igual a 0 o mayor a 366
 * Retorna 0 si ya se habÃ­a registrado un ticket para ese #visitor y ese #dayOfYear
 */
int addTicket(museumTicketADT museumTicketADT, size_t dayOfYear,  char * visitor);

/**
 * Retorna la cantidad de tickets registrados para visitar el museo el dÃ­a #dayOfYear del aÃ±o
 * Retorna -1 si #dayOfYear es igual a 0 o mayor a 366
 */
int dayTickets(const museumTicketADT museumTicketADT, size_t dayOfYear);

/**
 * Retorna la cantidad total de tickets registrados para visitar el museo (todos los dÃ­as del aÃ±o)
 */
int yearTickets(const museumTicketADT museumTicketADT);

/**
 * Funciones de iteraciÃ³n para poder consultar, para un dÃ­a #dayOfYear del aÃ±o,
 * los nombres de los visitantes de los tickets registrados para visitar el museo ese dÃ­a
 * en orden alfabÃ©tico por nombre de visitante.
 * IMPORTANTE: Permitir utilizar estas funciones para distintos dÃ­as del aÃ±o EN SIMULTANEO
 * (ver ejemplo en programa de prueba)
 * Abortar si cualquiera de las funciones es invocada con un #dayOfYear igual a 0 o mayor a 366
 */
void toBeginByDay(museumTicketADT museumTicketADT, size_t dayOfYear);

size_t hasNextByDay(museumTicketADT museumTicketADT, size_t dayOfYear);

char * nextByDay(museumTicketADT museumTicketADT, size_t dayOfYear);

/**
 * Libera los recursos utilizados para administrar las ventas de tickets para visitar un museo en un aÃ±o determinado
 */
void freeMuseumTicket(museumTicketADT museumTicketADT);

/**
 * Las funciones
 * - dayTickets
 * - yearTickets
 * - toBeginByDay
 * - hasNextByDay
 * - nextByDay
 * deben ser lo mÃ¡s eficiente posible
 */

/**
 * * * * *
 * Idea
 *  Tickets de entrada a un museo con nombre de visitante y dÃ­a del aÃ±o de validez
 *  Vector de listas donde
 *  - El vector es estÃ¡tico de 366 posiciones, una para cada dÃ­a
 *  - Dentro de cada posiciÃ³n, una lista ordenada de nombres de personas
 *  El iterador pide orden alfabÃ©tico y no se aceptan nombres repetidos para el mismo dÃ­a asÃ­ que tiene
 *  que ser lista ordenada sÃ­ o sÃ­.
 *  Se pide que el dayTickets y yearTickets sea eficiente asÃ­ que tienen que guardarse
 *  - Un contador de todos los tickets en el CDT (porque no hay remove)
 *  - El size de la lista de visitantes de un dÃ­a en particular en la estructura interna
 *  La "novedad" estÃ¡ en que el iterador no es uno y no estÃ¡ en el CDT sino que es uno por dÃ­a y estÃ¡
 *  en la estructura interna (en el tester hay un ejemplo mostrando que hago un next para el dÃ­a X y
 *  luego hago toBegin para el dÃ­a Y y los dos iteradores siguen funcionando correctamente).
 *  Al pedir que los iteradores por dÃ­a sean eficiente obliga a vector de listas y no una sola lista
 *  donde ordeno primero por dÃ­a y despuÃ©s desempato por nombre
 * * * * *
 * Sugerencia de quÃ© funciones pedir:
 * - newMuseumTicket
 * - dayTickets (retornar un campo del cdt y si hacen recorrido estÃ¡ mal)
 * - yearTickets (retornar un campo del cdt y si hacen recorrido estÃ¡ mal)
 * - toBeginByDay (las 3 de iteradores para pedir esto de N iteradores en simultÃ¡neo)
 * - hasNextByDay
 * - nextByDay
 * No pedimos el addTicket ni el freeMuseumTicket porque implican addRec y freeRec respectivamente
 * y quizÃ¡s aparece en otro ejercicio de parcial donde se requieran listas
 * * * * *
 * Para aumentar la dificultad se puede pedir:
 * - freeMuseumTicket y el freeRec que involucra pero sÃ³lo si no pedimos freeRec en otro ejercicio de parcial
 * - addTicket y el addRec que involucra pero sÃ³lo si no pedimos el addRec en otro ejercicio del parcial
 * - hasTicket que serÃ­a el getRec de la lista ordenada para ver si un visitante tiene un pase en tal dia
 * - Una funciÃ³n que retorne un array con todos los visitantes de tal dÃ­a
 * - Que se guarde una copia del nombre o que nextByDay retorne una copia y en el tester existan free de los strings
 * * * * *
 */