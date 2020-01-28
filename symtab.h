#ifndef _symtab_h
#define _symtab_h

#include <string>

using namespace std;

#define UNDEFINED NULL

typedef struct symtabCDT* symtabADT;

symtabADT NewSymbolTable(void);
void FreeSymbolTable(symtabADT table);
void Enter(symtabADT table, string key, void *value);
void *Lookup(symtabADT table, string key);

#endif
