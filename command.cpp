#include <string>
#include <iostream>
#include "symtab.h"

using namespace std;

typedef void (*commandFnT)(void);

typedef struct commandEntryST{
    commandFnT fn;
}* commandEntryT;

static symtabADT commandTable;

void ClearCmd(void)
{
    cout << "now clear everything" << endl;
}

void RunCmd(void)
{
    cout << "now running" << endl;
}

void HelpCmd(void)
{
    cout << "come to help" << endl;
}

void QuitCmd(void)
{
    cout << "now quit" << endl;
}

static void DefineCommand(string cmd, commandFnT fn)
{
    commandEntryT entry = new commandEntryST;

    entry->fn = fn;
    Enter(commandTable, cmd, (void *)entry);
}

static void InitCommandTable(void)
{
    commandTable = NewSymbolTable();
    DefineCommand("clear", ClearCmd);
    DefineCommand("run", RunCmd);
    DefineCommand("help", HelpCmd);
    DefineCommand("quit", QuitCmd);
}


static void ExecuteCommand(string cmd)
{
    void *value = Lookup(commandTable, cmd);
    if(value == UNDEFINED){
        cout << "no such command" << endl;
    }else{
        commandEntryT entry = (commandEntryT)value;
        entry->fn();
    }
}

int main(void)
{
    InitCommandTable();
    ExecuteCommand("clear");
    ExecuteCommand("help");
    ExecuteCommand("Quit");
    ExecuteCommand("quit");
    return 0;
}
