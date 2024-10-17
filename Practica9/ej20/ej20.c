#include <stdio.h>
#include <assert.h>



#define DIM 9

void setTaboo(char sudoku[DIM][DIM], size_t r, size_t c, size_t taboo[]) {
  // Marcamos como invalidos los que aparecen en la fila f y en la columna c
  for(size_t i=0; i < DIM; i++) {
    taboo[sudoku[r][i]] = 1;
    taboo[sudoku[i][c]] = 1;
  }
  // Ahora la submatriz
  size_t row = r / 3 * 3;
  size_t col = c / 3 * 3;
  for (size_t i=row; i < row + 3; i++) {
     for (size_t j=col; j < col +3; j++) {
       taboo[sudoku[i][j]] = 1;
     }
  }
}

int solverRec(char sudoku[DIM][DIM], size_t r, size_t c) {
  size_t j=c;
   for (size_t i=r; i < DIM; i++) {
     for (; j < DIM; j++) {
       if ( sudoku[i][j]==0) {
           // Ver que numeros puedo usar en [i][j]
           // Podriamos hacer una funcion que retorne un vector con los numeros validos,
           // pero teniendo en cuenta que son 9, usaremos un vector estatico que marque los numeros que no se pueden usar
           // Incluimos el cero, para simplificar su uso
           size_t taboo[DIM+1] = {0};
           setTaboo(sudoku, i, j, taboo);
           for(int e=1; e <= DIM; e++) {
             if ( !taboo[e]) {
               // Probamos con este, si tiene solucion, ya esta, sino probamos con el que sigue
               sudoku[i][j] = e;
               if ( solverRec(sudoku, i, j)) {
                  return 1;
               }
               // deshacemos, no fue solucion
               sudoku[i][j] = 0;
             }
           }
           // Probamos con todos y ninguno sirvio para esta casilla
           return 0;
       }
     }
     j = 0;
   }
   return 1;
}

int sudokuSolver(char matriz[DIM][DIM]) {
  // Para cada casilla libre debemos probar con todas las posibilidades
  // Completar la casilla libre con uno de los posibles numeros validos y probar con el resto de las casillas libres. Si con esa posiblidad no tiene solucion, hacer lo mismo con la siguiente posibilidad.
  // Para no tener que recorrer siempre la matriz desde el principio, usamos una funcion auxiliar que indica a partir de que casilla comnenzar a recorrer
  return solverRec(matriz, 0, 0);
}


int main(void) {
  // Una vacia tiene que tener solucion
  char sudoku[DIM][DIM] = {{0}};

  assert(sudokuSolver(sudoku)==1);
  for(int i=0; i < DIM; i++) {
    for(int j=0; j < DIM; j++) {
      printf("%1d ", sudoku[i][j]);
    }
    putchar('\n');
  }

  printf("\nUno sin solucion\n");
  char sudoku2[DIM][DIM] = {{1,2,3,4,5,6,7,8,9},
                           {5,6,7,8,9,1,2,3,4},
                           {8,9,1,2,3,7,5,6,0},
                          };

  assert(sudokuSolver(sudoku2)==0);
  for(int i=0; i < DIM; i++) {
    for(int j=0; j < DIM; j++) {
      printf("%1d ", sudoku2[i][j]);
    }
    putchar('\n');
  }

  printf("\nUno con solucion pero con celdas no vacias\n");
  char sudoku3[DIM][DIM] = {
    {0,2,0,3,0,0,0,0,0},
    {9,4,0,6,8,7,0,0,0},
    {1,6,0,0,0,0,0,0,0},
    {0,0,0,0,9,2,5,4,0},
    {0,0,0,0,6,0,0,0,0},
    {8,0,0,4,0,3,0,1,6},
    {0,1,0,0,7,6,0,8,2},
    {0,0,0,9,0,0,6,0,0},
    {7,0,6,0,0,4,9,3,0}
  };

  assert(sudokuSolver(sudoku3)==1);
  for(int i=0; i < DIM; i++) {
    for(int j=0; j < DIM; j++) {
      printf("%1d ", sudoku3[i][j]);
    }
    putchar('\n');
  }

  return 0;
}