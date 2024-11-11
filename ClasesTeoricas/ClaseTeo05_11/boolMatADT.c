#include "boolMatADT.h"


//LISTAS DE LISTAS

struct colNode {
    size_t col; // numero de columna
    struct colNode *colTail; // puntero a siguiente columna
};

struct rowNode {
    size_t row; // numero de fila
    struct rowNode *rowTail; // puntero a siguiente fila
    struct colNode *colFirst; // puntero a columna
};



typedef struct rowNode *rowList;
typedef struct colNode *colList;


struct boolMatCDT {
    rowList rowFirst; // puntero a primera fila
};

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
boolMatADT newBoolMat(void) {
    return calloc(1, sizeof(struct boolMatCDT));
}

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
colList setTrueColRec(colList c, size_t col) {
    if(c == NULL || c->col > col) { //hay que agregarla
        colList newCol = malloc(sizeof(struct colNode));
        newCol->col = col;
        newCol->colTail = c;
        return newCol;
    }
    if(c->col == col) { // no hace falta agregar nada
        return c;
    }
    c->colTail = setTrueColRec(c->colTail, col);
    return c;
}

static rowList setTrueRowRec(rowList l, size_t row, size_t col) {
    if(l == NULL || l->row > row) { // la fila no existe o hay que agregarlo en ese lugar
        rowList newRow = malloc(sizeof(struct rowNode));
        newRow->row = row;
        newRow->rowTail = l;
        newRow->colFirst = setTrueColRec(NULL, col);
        return newRow;
    }
    if(l->row == row) { //encontre la fila
        l->colFirst = setTrueColRec(l->colFirst, col);
    }
    l->rowTail = setTrueRowRec(l->rowTail, row, col);
    return l;

}
void setTrue(boolMatADT m, size_t row, size_t col) {
    m->rowFirst = setTrueRowRec(m->rowFirst, row, col);
}

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
static colList setFalseRecCol(colList c, size_t col, int *flag) {
    if(c == NULL || c->col > col) { // no encontro la columna
        return c; // deja tod.o como esta
    }
    if(c->col == col) {
        *flag = 1; // avisa que se elimino
        colList aux = c->colTail; // guarda el siguiente
        free(c); // libera el que hay que setear en false
        return aux; // devuelve el aux para conectar
    }
    c->colTail = setFalseRecCol(c->colTail, col, flag);
    return c;
}

static rowList setFalseRecRow(rowList l, size_t row, size_t col) {
    if(l == NULL || l->row > row) { // no encontro la fila
        return l;
    }
    if(l->row == row) {
        int flag = 0;
        l->colFirst = setFalseRecCol(l->colFirst, col, &flag); //busca la columna
        return l;
    }
    l->rowTail = setFalseRecRow(l->rowTail, row, col);
    return l;
}

void setFalse(boolMatADT m, size_t row, size_t col) {
    m->rowFirst =  setFalseRecRow(m->rowFirst, row, col);
}

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
static boolean getValueRecCol(const colList c, size_t col) {
    if(c == NULL || c->col > col) {
        return false;
    }
    if(c->col == col) {
        return true;
    }
    return getValueRecCol(c->colTail, col);
}

static boolean getValueRecRow(const rowList l, size_t row, size_t col) {
    if(l == NULL || l->row > row) {
        return false;
    }
    if(l->row == row) {
        return getValueRecCol(l->colFirst, col);
    }
    return getValueRecRow(l->rowTail, row, col);
}

boolean getValue(const boolMatADT m, size_t row, size_t col) {
    return getValueRecRow(m->rowFirst, row, col);
}

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------
static void freeBoolMatCol(colList c) {
    if(c == NULL)
        return;
    colList aux = c->colTail;
    free(c);
    freeBoolMatCol(aux);
}

static void freeBoolMatRow(rowList l) {
    if(l == NULL)
        return;
    rowList aux = l->rowTail;
    freeBoolMatCol(l->colFirst);
    free(l);
    freeBoolMatRow(aux);
}


void freeBoolMat(boolMatADT m) {
    freeBoolMatRow(m->rowFirst);
    free(m);
}

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

