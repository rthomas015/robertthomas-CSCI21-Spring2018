#ifndef node_h
#define node_h

#include <string>
#include "student.h"

using namespace std;

class Node {
    private:
        Student student_;
        Node* nextNode_;
        Node* prevNode_;
        
    public:
        //Constructor
        Node();
        
        //Destructor
        //~Node ();
        
        Node(Student aStu);
        
        Node(Student aStu, Node* nextNode, Node* prevNode);
        
        Student contents() const;
        
        Node* next_node() const;
        
        Node* prev_node() const;
        
        void set_contents (Student aStu);
        
        void set_next_node (Node* nextNode);
        
        void set_prev_node (Node* prevNode);
       
};

#endif