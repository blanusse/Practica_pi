//
//  main.c
//  random
//
//  Created by Marcelo Garberoglio on 28/08/2020.
//  Copyright © 2020 Marcelo Garberoglio. All rights reserved.
//
#include <assert.h>
#include "random.h"
#include <stdio.h>
#include "random.h"


int main(void) {
    int x;
    randomize();
    for(int i=0; i < 10; i++) {
        x = randInt(-10,10);
      //  x = randNormalize();
     assert(x>=-10 && x <= 10);
    }
    
  
    printf("OK!\n");
    return 0;
}

