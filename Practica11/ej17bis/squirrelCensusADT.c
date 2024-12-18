#include "squirrelCensusADT.h"

struct tRow {
    size_t *cols; // vector de columnas que va a tener la cantidad de poblacion en ese metro cuadrado
    size_t colDim; // cantidad de columnas
};

typedef struct tRow *tRowList;

struct squirrelCensusCDT {
    tRowList rows; //vector de  filas
    size_t rowDim; //cantidad de filas creadas
    size_t blockSize; // cuanto mide cada bloque
};






squirrelCensusADT newSquirrelCensus(size_t blockSizeMetres) {
    if(blockSizeMetres == 0) {
        return NULL;
    }
    squirrelCensusADT toRet = malloc(sizeof(struct squirrelCensusCDT));
    toRet->rows = NULL;
    toRet->rowDim = 0;
    toRet->blockSize = blockSizeMetres;
    return toRet;
}

size_t countSquirrel(squirrelCensusADT squirrelAdt, size_t yDistance, size_t xDistance) {
    int posY = yDistance/squirrelAdt->blockSize;
    int posX = xDistance/squirrelAdt->blockSize;
    if(posY >= squirrelAdt->rowDim) { //significa que tiene que agregar filas
        squirrelAdt->rows = realloc(squirrelAdt->rows, sizeof(struct tRow) * (posY + 1));
        for(int i=squirrelAdt->rowDim; i<=posY; i++) {
            squirrelAdt->rows[i].cols = NULL;
            squirrelAdt->rows[i].colDim = 0;
        }
        squirrelAdt->rowDim = posY+1;
    }
    if(posX >= squirrelAdt->rows[posY].colDim) { //significa que hay que agregar columnas
        squirrelAdt->rows[posY].cols = realloc(squirrelAdt->rows[posY].cols, sizeof(size_t) * (posX + 1));
        for(int i=squirrelAdt->rows[posY].colDim; i<=posX; i++) {
            squirrelAdt->rows[posY].cols[i] = 0;
        }
        squirrelAdt->rows[posY].colDim = posX+1;
    }
    return ++squirrelAdt->rows[posY].cols[posX];
}

size_t squirrelsInBlock(const squirrelCensusADT squirrelAdt, size_t yDistance, size_t xDistance) {
    int posY = yDistance/squirrelAdt->blockSize;
    int posX = xDistance/squirrelAdt->blockSize;
    if(posY > squirrelAdt->rowDim || posX >squirrelAdt->rows[posY].colDim) {
        return 0;
    }
    return squirrelAdt->rows[posY].cols[posX];
}

void freeSquirrelCensus(squirrelCensusADT squirrelAdt) {
    for(int i=0; i<squirrelAdt->rowDim; i++) {
        free(squirrelAdt->rows[i].cols);
    }
    free(squirrelAdt->rows);
    free(squirrelAdt);

}
