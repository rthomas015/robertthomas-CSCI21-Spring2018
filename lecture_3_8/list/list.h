/*LIST

Add this stuff:
Push(list, x) 	Inserts x on top of list 	Push(list, 44). list: 44, 99, 77
Pop(list) 	Returns and removes item at top of list 	Pop(list) returns: 99. list: 77
Peek(list) 	Returns but does not remove item at top of list 	Peek(list) returns 99. list still: 99, 77
IsEmpty(list) 	Returns true if list has no items 	IsEmpty(list) returns false.
GetLength(list) 	Returns the number of items in the list 	GetLength(list) returns 2. 

*/

#ifndef list_h
#define list_h

#include "node.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class list {
    
    private:
        Node* head;
        Node* tail;
    
    public:
        list();
        
        ~list();
        
        int size ();
    
        string print ();
        
        string peek();
    
        void pop ();
    
        void push (string name);
    
};

#endif