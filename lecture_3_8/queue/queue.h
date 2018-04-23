
#ifndef queue_H
#define queue_H

#include <iostream>
#include <sstream>
#include <string>
#include "node.h"

class Queue {
    private:
        Node* head;
        Node* tail;
        
    public:
        Queue();
        void push(string info);
        void pop();
        string print();
        string peek();
        int size();
};

#endif