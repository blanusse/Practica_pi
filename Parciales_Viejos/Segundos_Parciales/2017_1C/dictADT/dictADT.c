#include "dictADT.h"
#include <stdlib.h>
#include <string.h>




dictADT newDict();

void freeDict (dictADT m );

void addKey (dictADT d, const void * key, const void * value);

void * getValue (dictADT d, const void * key);

void ** keys (dictADT d) ;