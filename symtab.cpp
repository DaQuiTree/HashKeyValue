#include <string>
#include <iostream>
#include "symtab.h"

using namespace std;

#define NBuckets 101

typedef struct cellT{
    string key;
    void *value;
    struct cellT *link;
} cellT;

struct symtabCDT{
    cellT *buckets[NBuckets];
};

/*Private*/
static void FreeBucketChain(cellT *cp);
static cellT *FindCell(cellT *cp, string s);
static int Hash(string s, int nBuckets);

symtabADT NewSymbolTable(void)
{
    symtabADT table;
    int i;

    table = new symtabCDT;
    for(i = 0; i < NBuckets; i++)
       table->buckets[i] = NULL; 

    return table;
}

void FreeSymbolTable(symtabADT table)
{
    if(table == NULL)return;

    for(int i = 0; i < NBuckets; i++){
        if(table->buckets[i] != NULL)
            FreeBucketChain(table->buckets[i]);
    }

    delete table;
}

void Enter(symtabADT table, string key, void *value)
{
    int nBucket = Hash(key, NBuckets);
    cout <<"key: " << key << " hash to bucket: " << nBucket << endl;
    cellT *cp = FindCell(table->buckets[nBucket], key);
    if(cp == NULL){
        cp = new cellT;
        cp->key = key;
        cp->link = table->buckets[nBucket];
        table->buckets[nBucket] = cp;
    }
    cp->value = value; //update key-value
}

void *Lookup(symtabADT table, string key)
{
    cellT *pBucket = table->buckets[Hash(key, NBuckets)];
    cellT *cp = FindCell(pBucket, key);
    if(cp == NULL)
        return UNDEFINED;

    return cp->value;
}

static void FreeBucketChain(cellT *cp)
{
    cellT *np;

    while(cp != NULL){
        np = cp->link;
        delete cp;
        cp = np;
    }
}

static cellT *FindCell(cellT *cp, string s)
{
    while(cp != NULL){
        if(cp->key == s)
            break;
        else 
            cp = cp->link;
    }

    return cp;
}

#define Multiplier -1664117991L

static int Hash(string s, int nBuckets)
{
    unsigned long hashCode;
    unsigned int i;

    hashCode = 0;
    for(i = 0; i < s.length(); i++)
    {
        hashCode = hashCode * Multiplier + s[i];
    }
    
    int nbucket = hashCode % nBuckets;

    return(nbucket);
}

