#include "matrixADT.h"



typedef struct rowNode {
    elementType *elements; //vector de elementos que serian las columnas
    char *ocuppied; //para ver si la columna esta ocupada o no, el indice se corresponde con el de el vector de arriba
    size_t colCount;

}rowNode;


struct matrixCDT {
    rowNode *rowList; // vector de filas
    size_t rowCount;
};



//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

matrixADT newMatrix() {
    return calloc(1, sizeof(struct matrixCDT));
}

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------


int setElement(matrixADT m, size_t row, size_t col, elementType elem) {
    if(m->rowCount < row) { //significa que tiene que agrandar las filas
        m->rowList = realloc(m->rowList, sizeof(rowNode)*row);
        for(int i=m->rowCount; i<row; i++) {
            m->rowList[i].ocuppied = NULL;
            m->rowList[i].colCount = 0;
            m->rowList[i].elements = NULL;
        }
        m->rowCount = row;
    }
    if(m->rowList[row-1].colCount < col) { //significa que hay que agregar columnas
        m->rowList[row-1].elements = realloc(m->rowList[row-1].elements, sizeof(elementType) * col);
        m->rowList[row-1].ocuppied = realloc(m->rowList[row-1].ocuppied, sizeof(char)*col);
        for(int i=0; i<col; i++) {
            m->rowList[row-1].ocuppied[i] = 0;
        }
        m->rowList[row-1].colCount = col;
    }
    m->rowList[row-1].elements[col-1] = elem;
    m->rowList[row-1].ocuppied[col-1] = 1;
    return 1;
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

int getElement(matrixADT m, size_t row, size_t col, elementType * out) {
     if(row > m->rowCount || col > m->rowList[row-1].colCount ) {
         return 0;
     }
    if(m->rowList[row-1].ocuppied[col-1] == 0)
        return 0;
    *out = m->rowList[row-1].elements[col-1];
    return 1;
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

size_t rows(matrixADT m) {
    return m->rowCount;
}

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

void freeMatrix(matrixADT m) {
    for(int i=0; i<m->rowCount; i++) {
        free(m->rowList[i].elements);
        free(m->rowList[i].ocuppied);
    }
    free(m->rowList);
    free(m);
}
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

