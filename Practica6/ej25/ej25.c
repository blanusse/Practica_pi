#include <stdio.h>
#include <string.h>
#include <assert.h>

int subVector(const char arregloIn[], char arregloOut[], unsigned int start, unsigned int end, unsigned int dimMax) {

    if(start > end || strlen(arregloIn) < start)
        return 0;
    int j=0;
    for(int i=start; arregloIn[i] != '\0' && i<=end && j<dimMax-1; i++) {
        arregloOut[j++] = arregloIn[i];
    }
    arregloOut[j] = '\0';
    return j;
}


int main(void) {
    char s[100];
    assert(subVector("un texto", s,0,0,1)==0);
    assert(strcmp(s, "")==0);
    assert(subVector("un texto", s,0,0,10)==1);
    assert(strcmp(s, "u")==0);
    assert(subVector("un texto", s,0,10,1)==0);
    assert(strcmp(s, "")==0);

    assert(subVector("un texto", s,45,130,1)==0);


    assert(subVector("un texto", s,0,130,2)==1);
    assert(strcmp(s, "u")==0);

    assert(subVector("un texto", s,0,130,202)==8);
    assert(strcmp(s, "un texto")==0);

    assert(subVector("un texto", s,0,7,202)==8);
    assert(strcmp(s, "un texto")==0);

    assert(subVector("un texto", s,0,7,9)==8);
    assert(strcmp(s, "un texto")==0);

    assert(subVector("un texto", s,2,5,8)==4);
    assert(strcmp(s, " tex")==0);
  
    assert(subVector("un texto", s,45000,130000,10)==0);

    printf("OK!\n");
    return 0;
}