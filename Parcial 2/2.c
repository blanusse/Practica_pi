struct tNode{
  elemType elem; /*elemento*/
  size_t idx; /*indice del nodo*/
  struct tNode *tail; /*puntero al siguiente nodo*/
}

typedef struct tNode *tList;
typedef int (*cmp)(elemtype e1, elemType e2);

struct collectionCDT{
  tList list; /*lista de nodos*/
  tList current; /*puntero a nodo para iterar*/
  cmp pFunc; /*puntero a funcion para comparar elementos*/
  size_t colDim; /*cantidad de nodos en la coleccion*/
};


/*-----------------------------------------------------------------------------------------*/

collectionADT newCollection(cmp compare){
    collectionADT toReturn = malloc(sizeof(struct tNode));
    toReturn->list = NULL;
    toReturn->current = NULL;
    toReturn->pFunc = compare;
    toReturn->colDim = 0;
    return toReturn;
}
/*-----------------------------------------------------------------------------------------*/
static void moveIdxRec(tList l){
    if( l == NULL){
        return;
    }
    l->idx++;
    moveIdxRec(l->tail);
}

static tList addElementRec(tList l, elemType elem, size_t idx, int *currentIdx, int *flag){
    if(l == NULL || idx == 0){
    /*llego al final de la coleccion y no lo encontro, o encontro el indice donde va*/
        tList new = malloc(sizeof(struct tNode)); /*crea el nuevo nodo*/
        new->elem = elem; /*copia el nuevo elemento*/
        new->idx = currentIdx; /*coloca el indice*/
        *flag = 1; /*setea el flag en 1 para agrandar la cantidad*/
        new->tail = l; /*agrega el nuevo nodo antes del nodo actual*/
        /*si no lo agrega al final, hace que todo lo que resta de la coleccion aumente su idx*/
        moveIdxRec(l);
        return new;
    }
    (*currentIdx)++;
    l->tail = addElementRec(l->tail, elem, idx-1, currentIdx);
    return l;
}

void addElement(collectionADT collection, elemType elem, size_t idx){
    int currentIdx = 0; /*sirve para cuando ingresan el primer elemento con cualquier idx*/
    int flag = 0;
    collection->list = addElementRec(collection->list, elem, idx, currentIdx, &flag);
    collection->colDim += flag;
}
/*-----------------------------------------------------------------------------------------*/
int positionFirstRec(const tList l, elemType elem, cmp pFunc){
    if(l == NULL){ /*busco en toda la coleccion y no encontro el elemento*/
        return -1;
    }
    if(pFunc(l->elem, elem) == 0){ /*encontro el elemento, entonces retorna el idx*/
        return l->idx;
    }
    return(l->tail); /*paso recursivo*/
}

int positionFirst(const collectionADT collection, elemType elem){
    return positionFirstRec(collection->list, elem, collection->pFunc);
}
/*-----------------------------------------------------------------------------------------*/

void toBegin(collectionADT collection){
    collection->current = collection->list; /*setea el current en el nodo con idx = 0*/
}
/*-----------------------------------------------------------------------------------------*/

size_t hasNext(const collectionADT collection){
  return collection->current != NULL;
  /*si el elemento acutal en el iterador es el ultimo retorna 0*/
}
/*-----------------------------------------------------------------------------------------*/

elemType next(collectionADT collection){
    if(hasNext(collection)){
        elemType aux = collection->current->elem; /*guarda el elemento actual*/
        collection->current = collection->current->tail /*setea el current en el siguiente*/
        return aux;
    }
    /*si no tenia siguiente, aborta*/
    exit(1);
}



//CORRECCIONES


Estructura: Bien. Sería conveniente un puntero last.

newCollection: bien

addElement: El problema de usar idx en el nodo es que debería actualizar su valor cada vez que inserta un nuevo nodo (ineficiente), además de inicializarlo correctamente. En su implementación, lo hizo bien.

positionFirst: no escribe la llamada recursiva… sólo pone return (list->tail)

toBegin: bien

hasNext: bien

next: bien