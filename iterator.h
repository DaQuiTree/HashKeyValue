#ifndef _iterator_h
#define _iterator_h

#include "symtab.h"

typedef struct iteratorCDT *iteratorADT;

iteratorADT NewIterator(symtabADT table);
bool StepIterator(iteratorADT iterator, string &pKey);
void FreeIterator(iteratorADT iterator);

#endif
