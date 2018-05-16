#include <string>
#include <iostream>
#include "node.h"

using namespace std;

        //Constructor
        Node::Node() {
            //student_ = new Student;
            nextNode_ = NULL;
            prevNode_ = NULL;
        }
        
        Node::Node(Student aStu) {
            student_ = aStu;
            nextNode_ = NULL;
            prevNode_ = NULL;
        }
        
        Node::Node(Student aStu, Node* nextNode, Node* prevNode) {
            this->student_ = aStu;
            this->nextNode_ = nextNode;
            this->prevNode_ = prevNode;
        }
        
        //Destructor
       /* Node::~Node (){
            //this breaks stuff
            delete nextNode_;
        }*/
        
        //getContents
        Student Node::contents () const{
            return student_; 
        }
        
        Node* Node::next_node() const {
            return nextNode_;
        }
        
        Node* Node::prev_node() const {
            return prevNode_;
        }

        void Node::set_contents (Student aStu) {
            student_ = aStu;
        }
        
        void Node::set_next_node (Node* nextNode) {
            nextNode_ = nextNode;
        }
        
        void Node::set_prev_node (Node* prevNode) {
            prevNode_ = prevNode;
        }