/*

*/

#ifndef stack_h
#define stack_h

#include "node.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

template <class T>
class Stack {
    
    private:
        Node<T>* head;
        Node<T>* tail;
    
    public:
        Stack();
        
        ~Stack();
        
        int size ();
    
        string print ();
    
        void pop ();
    
        void push (T name);
        
        T peek_name();
    
};

#endif