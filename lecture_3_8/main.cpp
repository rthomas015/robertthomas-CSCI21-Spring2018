#include "node.h"
#include "list.h"
#include <string>
#include <iostream>

using namespace std;

int main () {
    
    //std::list<T> ;
    list newlist;
    
    newlist.push("Steve");
    newlist.push("Tammy1");
    newlist.push("Tammy2");
    cout << newlist.print();
    cout << newlist.size();
    newlist.pop();
    cout << endl << newlist.size();
    newlist.pop();
    cout << newlist.print();
    cout << newlist.size();
    newlist.pop();
    cout << newlist.print();
    cout << newlist.size();
    
    return 0;
}