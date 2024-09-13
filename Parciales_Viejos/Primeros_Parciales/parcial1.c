#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define EPSILON 1e-6
#define DIM	9
#define validNum(a)	((a) >= 0 && (a) <10) ? 1 : 0



/*
//EJ 1A
int analizaVector (const int v[], unsigned int dim, int *min, int *max, double *prom){

	int empty = 0;
	if (dim == 0){
		empty = 1;
	}
	else {
		*min = v[0];
		*max = v[0];
		*prom = v[0];	
	
		for(int i=1; i < dim; i++){
			
			if (v[i] > *max){
	
				*max = v[i];
			}
			if (v[i] < *min){
				*min = v[i];
			}
			*prom += v[i];
		}
		*prom /= dim;
	}	

	return !empty;
}




int main(void)
{
    int min = 3, max = 5;
    double average = 1.3;
    int v1[] = {3, 2, 3, 3, 4, 1, 10, 8, 6, 7};
    assert(!analizaVector(v1, 0, &min, &max, &average) && min == 3 && max == 5 && (average - 1.3 >= -EPSILON && average - 1.3 <= EPSILON));
    assert(analizaVector(v1, 3, &min, &max, &average) && min == 2 && max == 3 && (average - 2.666667 >= -EPSILON && average - 2.666667 <= EPSILON));
    assert(analizaVector(v1, 5, &min, &max, &average) && min == 2 && max == 4 && (average - 3 >= -EPSILON && average - 3 <= EPSILON));
    assert(analizaVector(v1, 8, &min, &max, &average) && min == 1 && max == 10 && (average - 4.25 >= -EPSILON && average - 4.25 <= EPSILON));
    assert(analizaVector(v1, 10, &min, &max, &average) && min == 1 && max == 10 && (average - 4.7 >= -EPSILON && average - 4.7 <= EPSILON));

    puts("OK!");
}

//-------------------------------------------------------------------//----------------------------------------------------------

//EJ 1B


int main(){

	int v[] = {1, 2, 3, 4, 5};
	int dim = sizeof(v)/sizeof(v[0]);
	int min, max;
	double prom;
	analizaVector(v, dim, &min, &max, &prom);

}

*/
//-------------------------------------------------------------------//----------------------------------------------------------
/*

//EJ 2

int rowAndColCheck(const int v[][DIM]){
	int error = 0;
	for(int i=0; i<DIM && error == 0; i++){
                int aux1[DIM] = {0};
                int aux2[DIM] = {0};
                for(int k=0; k<DIM && error == 0; k++){
                        
                        //Chequeo fila i//
                        
                        int rowCell = v[i][k]-1;
                        if (!validNum(rowCell) || aux1[rowCell] == 1){
                                error = 1;
                        }

                        else aux1[rowCell] = 1;

                        //Chequeo columna i

                        int colCell = v[k][i]-1;
                        if(!validNum(colCell) || aux2[colCell] == 1){
                                error = 1;
                        }

                        else aux2[colCell] = 1;
                }
	
	}
	return !error;
}

int blockCheck (const int v[][DIM], int dirX, int dirY){
	int error = 0;
	int aux[DIM] = {0};
	for(int i=0; i<DIM/3 && error == 0; i++){
	
		for(int k = 0; k <DIM/3 && error == 0; k++){
			
			int cell = v[dirX + i][dirY + k]-1;
			if (!validNum(cell) || aux[cell] == 1){
				error = 1;
			}
			else aux[cell] = 1;
		}
	}
	return !error;
}



int sudoku(const int v[][DIM]){
	int error = !rowAndColCheck(v);
        int matDir[DIM][2] = {{0, 0}, {0, 3}, {0, 6}, {3, 0}, {3, 3}, {3, 6}, {6, 0}, {6, 3}, {6, 6}};
	
	for(int i=0; i<DIM && error ==0; i++){
		if(!blockCheck(v, matDir[0][i], matDir[1][i]))
			error = 1;
	}
	
	return !error;		

}








int main()
{

    int m1[][DIM] = {
        {3, 8, 1, 9, 7, 6, 5, 4, 2},
        {2, 4, 7, 5, 3, 8, 1, 9, 6},
        {5, 6, 9, 2, 1, 4, 8, 7, 3},
        {6, 7, 4, 8, 5, 2, 3, 1, 9},
        {1, 3, 5, 7, 4, 9, 6, 2, 8},
        {9, 2, 8, 1, 6, 3, 7, 5, 4},
        {4, 1, 2, 6, 8, 5, 9, 3, 7},
        {7, 9, 6, 3, 2, 1, 4, 8, 5},
        {8, 5, 3, 4, 9, 7, 2, 6, 1},
    };
    assert(sudoku(m1));

    int m2[][DIM] = {
        {3, 8, 1, 9, 7, 6, 5, 4, 2},
        {2, 4, 7, 5, 9, 8, 1, 3, 6},
        {5, 6, 3, 2, 1, 4, 8, 7, 9},
        {6, 7, 4, 8, 5, 2, 3, 1, 9},
        {1, 3, 5, 7, 4, 9, 6, 2, 8},
        {9, 2, 8, 1, 6, 3, 7, 5, 4},
        {4, 1, 2, 6, 8, 5, 3, 9, 7},
        {7, 9, 6, 3, 2, 1, 4, 8, 5},
        {8, 5, 9, 4, 3, 7, 2, 6, 1},
    };
    assert(!sudoku(m2));

    int m3[][DIM] = {
        {3, 8, 1, 9, 7, 6, 5, 4, 2},
        {2, 3, 7, 5, 3, 8, 1, 9, 6},
        {5, 6, 9, 2, 1, 4, 8, 7, 3},
        {6, 7, 4, 8, 5, 2, 3, 1, 9},
        {1, 3, 5, 7, 4, 9, 6, 2, 8},
        {9, 2, 8, 1, 6, 3, 7, 5, 4},
        {4, 1, 2, 6, 8, 5, 9, 3, 7},
        {7, 9, 6, 3, 2, 1, 4, 8, 5},
        {8, 5, 3, 4, 9, 7, 2, 6, 1},
    };
    assert(!sudoku(m3));

    puts("OK!");
	return 0;
}

*/
//-----------------------------------------------------------------------------------------------------------------------------
/*
void eliminaApariciones (char v[]){
	int i=0, k=0;
	for(; v[i] != '\0'; i++){
		if (!isalpha(v[i]) || toupper(v[i]) != toupper(v[i+1])){
			v[k] = v[i];
			k++;
		}	
		
	}
	v[k] = '\0';

}


int main(){

	char v[] = "AaaA bcB";
	eliminaApariciones(v);
	for(int i=0; v[i] != '\0'; i++){
		printf("%c", v[i]);
	}


}












int main()
{
    char s1[] = "";
    eliminaApariciones(s1);
    assert(!strcmp(s1, ""));

    char s2[] = "aaA b[[[[b cc";
    eliminaApariciones(s2);
    assert(!strcmp(s2, "a b[[[[b c") || !strcmp(s2, "A b[[[[b c"));

    char s3[] = "aabbccaaaaaaa";
    eliminaApariciones(s3);
    assert(!strcmp(s3, "abca"));

    char s4[] = "    ";
    eliminaApariciones(s4);
    assert(!strcmp(s4, "    "));

    char s5[] = "AaAaAa";
    eliminaApariciones(s5);
    assert(!strcmp(s5, "a") || !strcmp(s5, "A"));

    char s6[] = "a,a,a,a,a,a,a";
    eliminaApariciones(s6);
    assert(!strcmp(s6, "a,a,a,a,a,a,a"));

    puts("OK!");
}



*/
//----------------------------__-----------------------------------------------------------------------------------------------//




int depura (int a[], unsigned int dimA, const int b[], unsigned int dimB){

	int dimC = dimA;
	for(int i=0;i < dimA;){
		for(int k=0; k<dimB; k++){

			if(a[i] == b[k]){
				dimC--;
				int aux = a[i];
				a[i] = a[i+1];
				a[i+1] = aux;
				
			}

		}

	}


	return dimC;

}



int main(){

	int v[] = {1, 2, 3, 4, 5};
	int v2[] = {1, 4, 5};
	int dim1 = sizeof(v)/sizeof(v[0]);
	int dim2 = sizeof(v2)/sizeof(v2[0]);
	int dim3;

	int a[] = {2, 3, 1, 2, 5, 6};
	int dimA = 3;
	ordena(a, dimA);
	for(int i=0; i<dimA; i++){
		printf("%d", a[i]);
	}	

	//dim3 = depura (v, dim1, v2, dim2);
	//for(int i=0; i<dim3; i++){
	//	printf("%d", v[i]);
	//}


}







