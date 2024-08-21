#include <stdio.h>
#define ENT_HORA 8
#define ENT_MINUTOS 5
llegaTemprano(const int hora, const int minutos){
    return(hora <= ENT_HORA && minutos <= ENT_MINUTOS);
}

int main() {
    return llegaTemprano(8, 3);
}