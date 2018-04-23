#ifndef doubly_H
#define doubly_H

#include <string>
#include <iostream>
#include <sstream>
#include "node.h"

using namespace std;

class doubly {
    private:
        Node* head;
        Node* tail;
        
    public:
    doubly();
    
    ~doubly();

    string print ();

    int size ();

    void pop ();

    void push (string name);

    string peek();
};

#endif