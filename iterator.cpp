#include <string>
#include <cstring>
#include "symtab.h"
#include "iterator.h"

using namespace std;

typedef struct cellT{
    string key;
    struct cellT *link;
} cellT;

struct iteratorCDT{
    cellT *start;
};

void InsertKey(string key, void *value, void *clientData)
{
    iteratorADT iter = (iteratorADT)clientData;
    cellT *prev, *next, *cp;
    
    prev = NULL;
    next = iter->start;
    //while(next != NULL && strcmp(key.c_str(), next->key.c_str()) > 0)
    while(next != NULL && key > next->key)
    {
        prev = next;
        next = next->link;
    }
    cp = new cellT;
    cp->key = key;
    cp->link = next;
    if(prev == NULL){
        iter->start = cp;
    }else{
        prev->link = cp;
    }
}

iteratorADT NewIterator(symtabADT table)
{
    iteratorADT iter = new iteratorCDT;
    iter->start = NULL;
    MapSymbolTable(InsertKey, table, (void*)iter);
    return iter;
}

bool StepIterator(iteratorADT iterator, string &pKey)
{
    cellT *cp = iterator->start;
    
    if(cp == NULL)return false;

    pKey = cp->key;
    iterator->start = cp->link;
    delete cp;

    return true;
}

void FreeIterator(iteratorADT iterator)
{
    cellT *cp = iterator->start;

    while(cp != NULL){
        cellT *np = cp->link;
        delete cp;
        cp = np;
    }

    delete iterator;
}
