//node
//creates a basic templated node which will comprise parts of the queue and the stack

#ifndef node_h
#define node_h

#include <string>

using namespace std;

//Templated Node Class
//only set up however to use strings based on cpp
template <class T>
class Node{
    private:
        T player_;
        Node<T>* nextNode_;
        Node<T>* prevNode_;
        
    public:
        //Constructor
        Node<T>();
        
        //Overloaded Constructor - creates node but with data
        //@param - T name - take in data of type T and initialize the contents of the node to that vlaue
        //@return - none
        Node<T>(T name);
        
        //Overloaded Constructor - creates node but with data and a pointer to the next node
        //@param - T name - take in data of type T and initialize the contents of the node to that vlaue
        //@param - Node* nextNode - takes in pointer to the nextNode
        //@param - Node* prevNode - takes in a pointer to the prevNode
        //@return - none
        Node<T>(T name, Node* nextNode, Node* prevNode);
        
        //contents - returns the contents of the node
        //@param - none
        //@return - returns contents of node of type T
        T contents() const;
        
        //next_node - returns the pointer information held in next_node
        //@param - none
        //@return - returns a Node* (pointer to the next Node in the Queue or Stack)
        Node<T>* next_node() const;
        
        //prev_node - returns the pointer information held in prev_node
        //@param - none
        //@return - returns a Node* (pointer to the prev Node in the Queue or Stack)
        Node<T>* prev_node() const;
        
        //Setters
        //set_contents - sets the contents of the node to some new information
        //@param - T newStudent - data of type T, to set the node's contents
        //@return - none
        void set_contents (T newStudent);
        
        //set_next_node - sets the next_node of the node to point at the pointer supplied as an argument
        //@param - Node* nextNode - pointer to a node object
        //@return - none
        void set_next_node (Node<T>* nextNode);
        
        //set_prev_node - sets the prev_node of the node to point at the pointer supplied as an argument
        //@param - Node* prevNode - pointer to a node object
        //@return - none
        void set_prev_node (Node<T>* prevNode);
        

};

#endif