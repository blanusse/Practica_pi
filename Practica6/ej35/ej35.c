#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>

int esVocal(char c) {
    c = toupper(c);

    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int acentos(const char text[]) {

    //Preguntar pq no me deja poner adentro del primer for la condicion text[i] != '\0'
    // Conviene eso pq con strleng lo hace menos eficiente


    int length = strlen(text);
    int count=0, i=0;
    for(; i<length; i++) {
        if (text[i] == '|') {
            int silabasRest = 1;
            char lastLetter = text[i];
            for(;text[i] != ' ' && text[i]; i++) {
                if(text[i] == '-')
                    silabasRest++;
                else
                    lastLetter = text[i];
            }
            if(silabasRest == 1 && (lastLetter=='n' || lastLetter == 's' || esVocal(lastLetter)))
                count++;
            else if(silabasRest == 2 && !(lastLetter=='n' || lastLetter == 's' || esVocal(lastLetter)))
                count++;
            else if(silabasRest > 2)
                count++;
        }
    }
    return count;
}


int main(void) {
    char s[] = "|El ca-|fe |del me-|nu |tie-ne |mal |gus-to";
    assert(2 == acentos(s));
    
    char s2[] = "Da-|mian com-|pro |es-te |ar-bol";
    assert(3 == acentos(s2));
    
    char s3[] = "";
    assert(0 == acentos(s3));
    
    char s4[] = " ";
    assert(0 == acentos(s4));
    
    assert(0 == acentos(""));
    assert(0 == acentos("A-pro-|ba-mos |el e-|xa-men"));
    assert(0 == acentos("A-pro-|ba-mos |el e-|xa-men   "));
    
    puts("OK!");
    return 0;
    
}