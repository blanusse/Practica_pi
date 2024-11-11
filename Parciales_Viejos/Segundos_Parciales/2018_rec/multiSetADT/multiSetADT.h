typedef struct multiSetCDT * multiSetADT;
typedef int elemType; // Tipo de elemento a insertar
/**
** Retorna 0 si los elementos son iguales, negativo si e1 es "menor" que e2 y positivo
** si e1 es "mayor" que e2
*/
static int compare (elemType e1, elemType e2) {
    return e1-e2;
}
/* Retorna un nuevo multiSet de elementos genéricos. Al inicio está vacío */
multiSetADT newMultiSet();
/* Inserta un elemento. Retorna cuántas veces está elem en el conjunto
** luego de haberlo insertado (p.e. si es la primera inserción retorna 1).
*/
unsigned int add(multiSetADT multiSet, elemType elem);
/* Retorna cuántas veces aparece el elemento en el multiSet */
unsigned int count(const multiSetADT multiSet, elemType elem);
/* Retorna la cantidad de elementos distintos que hay en el multiSet */
unsigned int size(const multiSetADT multiSet);
/* Elimina una repetición del elemento. Retorna cuántas veces está elem el conjunto
** luego de haberlo borrado (si el elemento no estaba, retorna cero)
*/
int removeM(multiSetADT multiSet, elemType elem);
/* Elimina todas las apariciones de un elemento. */
void removeAllM(multiSetADT multiSet, elemType elem);
/* Retorna un vector con los elementos que menos aparecen en el conjunto
** Si el conjunto está vacío retorna NULL
** En el parámetro de salida dim almacena la cantidad de elementos del vector
*/
elemType * minElements(const multiSetADT multiSet, int * dim);