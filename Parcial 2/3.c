TList addElem(TList l, char elem){
    if(l == NULL ){ /*recorrio toda la lista y no lo encontro*/
        TList new = malloc(sizeof(node));
        new->hits = 0;
        new->head = elem;
        new->tail = NULL;
        return new;
    }
    if(l->head == elem){
        l->hits++;
        return l;
    }
    tList aux = addElem(l->tail, elem);
    if(aux->hits > l->hits){
        tList aux2 = aux->tail;
        aux->tail = l;
        l->hits = aux2;
        return aux;
    }
    l->tail = aux;
    return l;
}