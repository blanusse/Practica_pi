
typedef struct dictCDT *dictADT;

typedef char * elemType;

dictADT newDict();

void freeDict (dictADT m );

void addKey (dictADT d, const void * key, const void * value);

elemType getValue (dictADT d, const void * key);

int * keys (dictADT d) ;