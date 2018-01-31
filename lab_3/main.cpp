#include <iostream>
#include <string>
#include "lab_3.h"

using namespace std;

int main () {
    cout << "This program will test a few functions..." << endl;
    
    cout << Goldilocks("bed", 3);
    cout << RockScissorPaper('s','p');
    
    cout << ToLower("TEST");
    cout << ToUpper("test");
    
    return 0;
}