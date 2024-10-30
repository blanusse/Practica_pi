#include "rankingADT.h"


typedef struct rankingCDT {
    elemType *vec;
    compare pFunc;
    size_t rankingDim;
}rankingCDT;


rankingADT newRanking(elemType elems[], size_t dim, compare cmp) {
    rankingADT toReturn = calloc(1, sizeof(rankingCDT));
    toReturn->pFunc = cmp;
    if(dim ==0) {
        return toReturn;
    }
    toReturn->vec = malloc(sizeof(elemType)*dim);
    for(int i=0; i<dim; i++) {
        toReturn->vec[i] = elems[i];
        toReturn->rankingDim++;
    }
    return toReturn;
}

void addRanking(rankingADT ranking, elemType elem) {
    for(int i=0; i<ranking->rankingDim; i++) {
        if(ranking->pFunc(ranking->vec[i], elem) == 0) { // significa que encontro uno igual
            if(i!=0) {
                elemType aux = ranking->vec[i];
                ranking->vec[i] = ranking->vec[i-1];
                ranking->vec[i-1] = aux;
                 //lo encontro, lo cambio y sale de la funcion
            }
            return; // lo encontro, pero como ya esta primero no hace falta moverlo
        }
    }
    ranking->vec = realloc(ranking->vec, sizeof(elemType)*(ranking->rankingDim + 1));
    ranking->vec[ranking->rankingDim] = elem;
    ranking->rankingDim++;
}

size_t size(const rankingADT ranking) {
    return ranking->rankingDim;
}

int getByRanking(rankingADT ranking, size_t n, elemType * elem) {
    if(n==0 || n>=ranking->rankingDim) {
        return 0;
    }
    *elem = ranking->vec[n-1];
    if(n != 1) {
        elemType aux = ranking->vec[n-1];
        ranking->vec[n-1] = ranking->vec[n-2];
        ranking->vec[n-2] = aux;
    }


    return 1;
}

elemType * getTopRanking(const rankingADT ranking, size_t * top) {
    if(*top == 0)
        return NULL;
    elemType *toReturn = malloc(*top * sizeof(elemType));
    int i=0;
    for(; i<ranking->rankingDim && i<*top; i++) {
        toReturn[i] = ranking->vec[i];
    }
    *top = i;
    return toReturn;
}

int contains(rankingADT ranking, elemType elem) {
    int found = 0;
    for(int i=0; !found && i<ranking->rankingDim; i++) {
        if(ranking->pFunc(ranking->vec[i], elem) == 0) {
            found = 1;
            if(i != 0) {
                elemType aux = ranking->vec[i];
                ranking->vec[i] = ranking->vec[i-1];
                ranking->vec[i-1] = aux;
            }

        }
    }
    return found;
}

void downByRanking(rankingADT ranking, size_t n) {
    if(n != 0 && n < ranking->rankingDim-1) {
        elemType aux = ranking->vec[n-1];
        ranking->vec[n-1] = ranking->vec[n];
        ranking->vec[n] = aux;
    }
}

void freeRanking(rankingADT r) {
    free(r->vec);
    free(r);
}

int position(const rankingADT r, elemType elem) {
    int i=0, found = 0;
    for(; !found && i<r->rankingDim; i++) {
        if(r->pFunc(r->vec[i], elem) == 0) {
            found = 1;
        }
    }
    if(found) {
        return i;
    }
    return 0;
}