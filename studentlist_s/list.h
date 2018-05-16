#ifndef list_H
#define list_H

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "Iterator.h"
#include "node.h"
#include "student.h"

using namespace std;

class list {
    private:
        Node* head;
        Node* tail;
        
    public:
    list();
    
    ~list();

    string print ();

    //bool insert(int location, Student aStu);
    
    //bool remove(string data);
    
    int size ();
    
    void sort();

    void pop ();

    void push (Student aStu);

    Student peek();
    
    //friend class Iterator
    friend class Iterator;
        
    //Returns an iterator to the front of the Queue
    Iterator begin();
        
    //Returns an iterator to one past the end of the line/Queue
    Iterator end();
        
    //Returns an iterator to the end of the line/Queue (the head)
    Iterator rbegin();
    
};

#endif