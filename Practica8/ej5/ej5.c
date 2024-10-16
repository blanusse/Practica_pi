#include <math.h>
#include <stdio.h>

#include "../../Lib/getnum.h"
#include "../../Lib/random.h"

typedef struct {
    int x;
    int y;
}posicion;


int movimiento(posicion particula, int radio) {
    particula.x = 0;
    particula.y = 0;
    int i;
    for(i=0; pow(particula.x, 2) + pow(particula.y, 2) < pow(radio, 2); i++) {
        int randMov = randInt(0, 3);
        if(randMov == 0) {
            particula.x -= 1;
        }
        else if(randMov == 1) {
            particula.x += 1;
        }
        else if(randMov == 2) {
            particula.y -= 1;
        }
        else if(randMov == 3) {
            particula.y += 1;
        }
        // printf("%d\t%d\n", particula.x, particula.y);
    }
    return i;
}

int main() {
    randomize();
    printf("Radio   Tiempo   Relacion\n");
    for(int i=1; i<10; i++) {
        posicion particula = {0,0};
        int tiempo = movimiento(particula, i);
        printf("%d\t%5.d\t%7.f\n", i, tiempo, (double)i /tiempo);
    }
}