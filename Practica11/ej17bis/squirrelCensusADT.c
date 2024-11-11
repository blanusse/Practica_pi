#include "squirrelCensusADT.h"

struct rowElem {
    size_t *cols;
    size_t colDim;
};

typedef struct rowElem *rowList;

struct squirrelCensusCDT {
    rowList rows;
    size_t rowDim;
    size_t blockSizeMeters;
};


squirrelCensusADT newSquirrelCensus(size_t blockSizeMetres) {
    squirrelCensusADT toReturn = malloc(sizeof(struct squirrelCensusCDT));
    toReturn->rows = NULL;
    toReturn->rowDim = 0;
    toReturn->blockSizeMeters = blockSizeMetres;
    return toReturn;

}

size_t countSquirrel(squirrelCensusADT squirrelAdt, size_t yDistance, size_t xDistance) {
    size_t yBlock = yDistance /squirrelAdt->blockSizeMeters;
    size_t xBlock = xDistance / squirrelAdt->blockSizeMeters;
    if(yBlock >= squirrelAdt->rowDim) {
        squirrelAdt->rows = realloc(squirrelAdt->rows, sizeof(struct rowElem)*(yBlock + 1));
        for(size_t i=squirrelAdt->rowDim; i<=yBlock; i++) {
            squirrelAdt->rows[i].cols = NULL;
            squirrelAdt->rows[i].colDim = 0;
        }
        squirrelAdt->rowDim = yBlock+1;
    }
    if(xBlock >= squirrelAdt->rows[yBlock].colDim) {
        squirrelAdt->rows[yBlock].cols = realloc(squirrelAdt->rows[yBlock].cols, sizeof( size_t)*(xBlock + 1));
        for(size_t i=squirrelAdt->rows[yBlock].colDim; i<=xBlock; i++) {
            squirrelAdt->rows[yBlock].cols[i] = 0;
        }
        squirrelAdt->rows[yBlock].colDim = xBlock+1;
    }
    return ++squirrelAdt->rows[yBlock].cols[xBlock];
}

size_t squirrelsInBlock(const squirrelCensusADT squirrelAdt, size_t yDistance, size_t xDistance) {
    size_t yBlock = yDistance /squirrelAdt->blockSizeMeters;
    size_t xBlock = xDistance / squirrelAdt->blockSizeMeters;

    if(yBlock >= squirrelAdt->rowDim ||xBlock >= squirrelAdt->rows[yBlock].colDim) {
        return 0;
    }

    return squirrelAdt->rows[yBlock].cols[xBlock];
}

void freeSquirrelCensus(squirrelCensusADT squirrelAdt) {

    for(size_t i=0; i<squirrelAdt->rowDim; i++) {
        free(squirrelAdt->rows[i].cols);
    }
    free(squirrelAdt->rows);
    free(squirrelAdt);
}
