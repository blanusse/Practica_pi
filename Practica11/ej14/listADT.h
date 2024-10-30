


typedef struct listCDT * listADT;
 
typedef int elemType;  	// Tipo de elemento a insertar, por defecto int

typedef int (*cmp) (elemType e1, elemType e2);
/* Retorna una lista vacía.
** compare retorna 0 si los elementos son iguales, negativo si e1 es "menor" que e2 y 
** positivo si e1 es "mayor" que e2
*/
listADT newList(int (*compare) (elemType e1, elemType e2));

/* Agrega un elemento. Si ya estaba no lo agrega */
void add(listADT list, elemType elem);

/* Elimina un elemento. */
void delete(listADT list, elemType elem);

/* Resetea el iterador que recorre la lista en el orden de inserción */
void toBegin(listADT list);

/* Retorna 1 si hay un elemento siguiente en el iterador que
** recorre la lista en el orden de inserción. Sino retorna 0
*/
int hasNext(listADT list);

/* Retorna el elemento siguiente del iterador que recorre la lista
** en el orden de inserción. 
** Si no hay un elemento siguiente o no se invocó a toBegin aborta la ejecución.
*/
elemType next(listADT list);

/* Resetea el iterador que recorre la lista en forma ascendente */
void toBeginAsc(listADT list);

/* Retorna 1 si hay un elemento siguiente en el iterador
** recorre la lista en forma ascendente. Sino retorna 0
*/
int hasNextAsc(listADT list);

/* Retorna el elemento siguiente del iterador que recorre la lista en forma ascendente.
** Si no hay un elemento siguiente o no se invocó a toBeginAsc aborta la ejecución.
*/
elemType nextAsc(listADT list);

/* Libera la memoria reservada por la lista */
void freeList(listADT list);

