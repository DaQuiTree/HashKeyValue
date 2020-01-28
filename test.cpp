#include <iostream>

using namespace std;

#define multiplier -1664117991L

int main()
{
    unsigned long hashcode = multiplier * 'a' + 'a';
    int nbucket = hashcode % 101;

    cout << "hashcode:" << hashcode << endl;
    cout << "nbucket:" << nbucket << endl;
}
