#include <string>
#include <iostream>
#include "node.h"

using namespace std;

        //Constructor
        Node::Node() {
            student_ = "";
            nextNode_ = NULL;
        }
        
        Node::Node(string name) {
            student_ = name;
            nextNode_ = NULL;
        } 
        
        Node::Node(string name, Node* nextNode, Node* prevNode) {
            this->student_ = name;
            this->nextNode_ = nextNode;
            this->prevNode_ = prevNode;
        }
        
        //Destructor
       /* Node::~Node (){
            //this breaks stuff
            delete nextNode_;
        }*/
        
        //getContents
        string Node::contents () const{
            return student_; 
        }
        
        Node* Node::next_node() const {
            return nextNode_;
        }
        
        Node* Node::prev_node() const {
            return prevNode_;
        }

        void Node::set_contents (string newStudent) {
            student_ = newStudent;
        }
        
        void Node::set_next_node (Node* nextNode) {
            nextNode_ = nextNode;
        }
        
        void Node::set_prev_node (Node* prevNode) {
            prevNode_ = prevNode;
        }