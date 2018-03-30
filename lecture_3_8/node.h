#ifndef node_h
#define node_h

#include <string>

//using namespace std;

class Node {
    private:
        std::string student_;
        Node* nextNode_;
        
    public:
        //Constructor
        Node();
        
        //Destructor
        ~Node ();
        
        Node(std::string name);
        
        Node(std::string name, Node* nextNode);
        
        std::string contents() const;
        
        Node* next_node() const;
        
        void set_contents (std::string newStudent);
        
        void set_next_node (Node* nextNode);
       
        void pop ();
        
        int size (Node &head);
};

#endif