#include <stdio.h>
#include <string.h>


int esCapicua(char palabra[], int dim) {
    if(dim <= 1) {
        return 1;
    }
    if(*palabra != palabra[dim-1]) {
        return 0;
    }
    return esCapicua(++palabra, dim-2);
}

int esCapicuaWrapper(char palabra[]) {
    int tam = strlen(palabra);
    return esCapicua(palabra, tam);
}


int main() {
    char v[] = "larutanatural";
    // printf("%d\n", strlen(v));
    printf("%d", esCapicuaWrapper(v));
}
