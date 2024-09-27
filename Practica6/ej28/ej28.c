#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>

#define EXITO 1
#define ERROR 0
#define CANT_VOC    5



int whichVocal(char c) {
    c = toupper(c);
    char *aux = "AEIOU";
    char *p = strchr(aux, c);
    if(p == NULL)
        return 0;
    return p-aux +1;
}



int elimVocales(char text[], unsigned int m[][CANT_VOC], unsigned int n) {
    int error = 0;
    int j=0;
    int vocCount[CANT_VOC] = {0};
    for(int i=0; text[i]; i++) {
        int voc = whichVocal(text[i]);
        if( voc && n-1 > vocCount[voc-1]){
            m[vocCount[voc-1]][voc-1] = i;
            vocCount[voc-1]++;
        }
        else {
            if(voc) {
                error = 1;
            }
            text[j++] = text[i];
        }

    }
    for(int i=0; i<CANT_VOC; i++)
        m[vocCount[i]][i] = -1;

    text[j] = 0;
    return !error;

}


// int main() {
//     char s[] = "las buenas ideas escasean, si";
//     int m[1][CANT_VOC];
//     elimVocales(s, m, 1);
//     printf("%s\n", s);
//     for(int i=0; i<1; i++) {
//         for(int k=0; k<CANT_VOC; k++) {
//             printf("%d\t", m[i][k]);
//         }
//         printf("\n");
//     }
// }






int main(void) {
    int m[6][CANT_VOC];
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

