#include <iostream>
#include "symtab.h"

using namespace std;

int main()
{
    symtabADT table = NewSymbolTable();

    Enter(table, "daqui", (void*)"666");
    Enter(table, "miley", (void*)"6664");
    Enter(table, "zhengxisheng", (void*)"11111111111");
    Enter(table, "lixiaoqing", (void*)"sdfwer");
    Enter(table, "yangchaolong", (void*)"33212131");

    cout << "daqui:" << (char *)Lookup(table, "daqui") << endl;
    //cout << "daqui1" << (char *)Lookup(table, "daqui1") << endl;
    Enter(table, "daqui", (void*)"555");
    cout << "new daqui:" << (char *)Lookup(table, "daqui") << endl;
    cout << "yangchaolong" << (char *)Lookup(table, "yangchaolong") << endl;

    FreeSymbolTable(table);
}
