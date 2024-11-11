#include <stdlib.h>
#include <string.h>

typedef struct hangmanCDT * hangmanADT;

/* Crea la estructura que dará soporte al almacenamiento y selección de palabras
** maxLevel: la cantidad máxima de niveles de dificultad que soportará (como mínimo 1)
** Los niveles válidos serán de 1 a maxLevel inclusive
 */
hangmanADT newHangman(unsigned int maxLevel);


/* Agrega un conjunto de palabras asociadas a un nivel de dificultad.
** El arreglo words[] está finalizado en NULL
** Si alguna de las palabras de words[] ya existe en el hangmanADT para ese nivel de dificultad
** se ignora.
** No se realiza una copia local de cada palabra sino únicamente los punteros recibidos
** Si el nivel supera la cantidad máxima definida en newHangman, se ignora y retorna -1
** Retorna cuántas palabras se agregaron al nivel
*/
int addWords(hangmanADT h, char * words[], unsigned int level);


/* Retorna cuántas palabras hay en un nivel, -1 si el nivel es inválido */
int size(const hangmanADT h, unsigned int level);


/* Retorna una palabra al azar de un nivel determinado, NULL si no hay palabras de ese nivel
** o si el nivel es inválido.
*/
char * word(const hangmanADT h, unsigned int level);


/* Retorna todas las palabras de un nivel, o NULL si el nivel es inválido
** El último elemento del vector es el puntero NULL
*/
char ** words(const hangmanADT h, unsigned int level);


void freeHangman(hangmanADT h);
