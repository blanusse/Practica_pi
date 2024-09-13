#include <stdio.h>
#include <assert.h>
#define FILS	3
#define COLS 6

//EJ1


#define ES_VOCAL(a)	(toupper((a)) == 'A' || toupper((a)) == 'E' || toupper ((a)) == 'I' || toupper((a)) == 'O' || toupper((a)) == 'U'



#define TO_LOWER(a)	((a) >= 'A' && (a) <= 'Z') ? ((a) - 'A' + 'a'  : (a)


//--------------------------------------------------------------------------------------------------------------------------------

//EJ2
/*
int matrizAscDesc (int a[][COLS]){
	int asc = 0, desc = 0;
	for(int i=0; i<FILS && (!asc || !desc); i++){

		for(int k=0; k<COLS-1 && (!desc || !asc); k++){
			if(a[i][k] > a[i][k+1]){
				desc = 1;	
			}
			else if(a[i][k] < a[i][k+1]){
				asc = 1;
			}
		}
		if((a[i][COLS-1] > a[i+1][0]) && i <FILS-1)
			desc = 1;
		else if ((a[i][COLS-1] < a[i+1][0]) && i < FILS-1)
			asc = 1;
	}
	if(!asc && desc)
		return -1;
	if (asc && !desc)
		return 1;
	
	return 0;
				

}


int main()
{

    int m1[][COLS] = {
        {-6, -5, 2, 6},
        {7, 9, 9, 14},
        {21, 32, 45, 46}};
    int res = matrizAscDesc(m1);
    assert(res == 1);

    int m2[][COLS] = {
        {19, 13, 12, 8},
        {7, 7, 5, -1},
        {-6, -10, -14}};
    res = matrizAscDesc(m2);
    assert(res == -1);

    int m3[][COLS] = {
        {-6, -5, -6, 6},
        {7, 9, 10, 14},
        {21, 32, 45, 46}};
    res = matrizAscDesc(m3);
    assert(res == 0);

    int m4[][COLS] = {{19, 13, 18, 8}, {7, 5, 2, -1}, {-6, -10, -14}};
    res = matrizAscDesc(m4);
    assert(res == 0);

    int m5[][COLS] = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}};
    res = matrizAscDesc(m5);
    assert(res == 1 || res == -1);

    int m6[][COLS] = {{19, 13, 12, 8}, {9, 5, 2, -1}, {-6, -10, -14}};
    res = matrizAscDesc(m6);
    assert(res == 0);

    puts("OK!");
}

*/
//--------------------------------------------------------------------------------------------------------------------------------

//EJ3

void interseccion (const int m1[][COLS], const int m2[][COLS], int res[][COLS]){
	int countRes = 0, found =0;
	for(int i=0; i<FILS; i++){
		countRes = 0;
		for(int k=0; k<COLS; k++){
			int found = 0;
			for(int j=0; j< COLS && !found; j++){
				if(m1[i][k] == m2[i][j]){
					found = 1;
					res[i][countRes] = m1[i][k];
					countRes++;				
				}
			}
		}
		while(countRes < COLS){
			res[i][countRes] = 0;
			countRes++;
		}
	}

}


int main()
{
    int m1[FILS][COLS] = {{1, 2, 3, 4, 5, 6},
                          {2, 1, 2, 1, 3, 1},
                          {10, 9, 4, 3, 10, 5}};
    int m2[FILS][COLS] = {{6, 2, 1, 4, 5, 3},
                          {1, 1, 2, 3, 3, 1},
                          {1, 19, 7, 8, 1, 15}};
    int m3[FILS][COLS];
    interseccion(m1, m2, m3);
    int expected[FILS][COLS] = {{1, 2, 3, 4, 5, 6},
                                {2, 1, 3, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0}};
    sonIguales(expected, m3);

    int m4[FILS][COLS] = {{1, 2, 3, 4, 5, 6},
                          {2, 1, 2, 1, 3, 1},
                          {10, 9, 4, 3, 10, 5}};
    int m5[FILS][COLS] = {{6, 2, 1, 4, 28, 29},
                          {1, 1, 331, 3, 3, 1},
                          {1, 19, 7, 4, 1, 15}};
    int m6[FILS][COLS];
    interseccion(m4, m5, m6);
    int expected[FILS][COLS] = {{1, 2, 4, 6, 0, 0},
                                {1, 3, 0, 0, 0, 0},
                                {4, 0, 0, 0, 0, 0}};
    sonIguales(expected, m6);

    int m7[FILS][COLS] = {{1, 1, 1, 1, 1, 1},
                          {3, 2, 25, 4, 9, 10},
                          {10, 9, 4, 3, 10, 5}};
    int m8[FILS][COLS] = {{1, 1, 1, 1, 1, 1},
                          {10, 25, 3, 100, 200, 300},
                          {5, 4, 9, 10, 3, 112}};
    int m9[FILS][COLS];
    interseccion(m7, m8, m9);
    int expected[FILS][COLS] = {{1, 0, 0, 0, 0, 0},
                                {3, 25, 10, 0, 0, 0},
                                {10, 9, 4, 3, 5, 0}};
    sonIguales(expected, m9);

    puts("OK!");
}
