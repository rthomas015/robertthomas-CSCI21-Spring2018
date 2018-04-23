#ifndef node_h
#define node_h

#include <string>

using namespace std;

class Node {
    private:
        string student_;
        Node* nextNode_;
        Node* prevNode_;
        
    public:
        //Constructor
        Node();
        
        //Destructor
        //~Node ();
        
        Node(string name);
        
        Node(string name, Node* nextNode, Node* prevNode);
        
        string contents() const;
        
        Node* next_node() const;
        
        Node* prev_node() const;
        
        void set_contents (string newStudent);
        
        void set_next_node (Node* nextNode);
        
        void set_prev_node (Node* prevNode);
       
};

#endif