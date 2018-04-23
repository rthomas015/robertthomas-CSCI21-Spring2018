/*

*/

#ifndef stack_h
#define stack_h

#include "node.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class stack {
    
    private:
        Node* head;
        Node* tail;
    
    public:
        stack();
        
        ~stack();
        
        int size ();
    
        string print ();
    
        void pop ();
    
        void push (string name);
        
        string peek();
    
};

#endif