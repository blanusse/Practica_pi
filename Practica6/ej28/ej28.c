#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#define EXITO 1
#define ERROR 0

#define CANT_VOCAL  5

int esVocal(char c) {
    c = toupper(c);
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}


int elimVocales(char text[], unsigned int m[][CANT_VOCAL], int n) {
    int error = 0;
    int j=0;
    int indexA = 0, indexE = 0, indexI = 0, indexO = 0, indexU = 0;
    for(int i=0; text[i];i++) {
        if(!esVocal(text[i])) {
            text[j++] = text[i];
        }
        else if(indexA < n && indexE < n && indexI < n && indexO < n && indexU < n) {
            if(toupper(text[i]) == 'A') {
                m[indexA++][0] = i;
            }
            else if(toupper(text[i]) == 'E') {
                m[indexE++][1] = i;
            }
            else if(toupper(text[i]) == 'I') {
                m[indexI++][2] = i;
            }
            else if(toupper(text[i]) == 'O') {
                m[indexO++][3] = i;
            }
            else if(toupper(text[i]) == 'U') {
                m[indexU++][4] = i;
            }
        }
    }
    if(indexA == n || indexE==n || indexI == n || indexO==n || indexU == n) {
        error = 1;
    }
    else {
        m[indexA][0] = -1;
        m[indexE][1] = -1;
        m[indexI][2] = -1;
        m[indexO][3] = -1;
        m[indexU][4] = -1;
    }
    text[j] = 0;
    return !error;
}


int main(void) {
    int m[6][CANT_VOCAL];
    char s[] = "las buenas ideas escasean, si";

    assert(elimVocales(s, m, 6)==EXITO);
    assert(strcmp(s, "ls bns ds scsn, s")==0);
    assert(m[0][0] == 1);
    assert(m[1][0] == 8);
    assert(m[2][0] == 14);
    assert(m[3][0] == 20);
    assert(m[4][0] == 23);
    assert(m[5][0] == -1);

    assert(m[0][1] == 6);
    assert(m[1][1] == 13);
    assert(m[2][1] == 17);
    assert(m[3][1] == 22);
    assert(m[4][1] == -1);

    assert(m[0][2] == 11);
    assert(m[1][2] == 28);
    assert(m[2][2] == -1);

    assert(m[0][3] == -1);

    assert(m[0][4] == 5);
    assert(m[1][4] == -1);

    strcpy(s, "las buenas ideas escasean, si");
    assert(elimVocales(s, m, 1)==ERROR);
    assert(strcmp(s, "las buenas ideas escasean, si")==0);
    assert(m[0][0]==-1);
    assert(m[0][1]==-1);
    assert(m[0][2]==-1);
    assert(m[0][3]==-1);
    assert(m[0][4]==-1);

    assert(elimVocales(s, m, 5)==ERROR);
    assert(strcmp(s, "ls bns ds scsan, s")==0);
    assert(m[0][0] == 1);
    assert(m[1][0] == 8);
    assert(m[2][0] == 14);
    assert(m[3][0] == 20);
    assert(m[4][0] == -1);

    assert(m[0][1] == 6);
    assert(m[1][1] == 13);
    assert(m[2][1] == 17);
    assert(m[3][1] == 22);
    assert(m[4][1] == -1);

    assert(m[0][2] == 11);
    assert(m[1][2] == 28);
    assert(m[2][2] == -1);

    assert(m[0][3] == -1);

    assert(m[0][4] == 5);
    assert(m[1][4] == -1);

    printf("OK!\n");
    return 0;
}

