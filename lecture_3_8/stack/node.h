#ifndef node_h
#define node_h

#include <string>

using namespace std;

class Node {
    private:
        string student_;
        Node* nextNode_;
        
    public:
        //Constructor
        Node();
        
        //Destructor
        //~Node ();
        
        Node(string name);
        
        Node(string name, Node* nextNode);
        
        string contents() const;
        
        Node* next_node() const;
        
        void set_contents (string newStudent);
        
        void set_next_node (Node* nextNode);
       
};

#endif