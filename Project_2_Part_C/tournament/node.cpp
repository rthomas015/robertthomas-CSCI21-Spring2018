#include <string>
#include <iostream>
#include "node.h"

using namespace std;

        //Constructor
        template<typename T>
        Node<T>::Node() {
            nextNode_ = NULL;
        }
        
        template<typename T>
        Node<T>::Node(T name) {
            player_ = name;
            nextNode_ = NULL;
        }
        
        template<typename T>
        Node<T>::Node(T name, Node<T>* nextNode) {
            player_ = name;
            nextNode_ = nextNode;
        }
        
        template<typename T>
        T Node<T>::contents () const{
            return player_; 
        }
        
        template<typename T>
        Node<T>* Node<T>::next_node() const {
            return nextNode_;
        }

        template<typename T>
        void Node<T>::set_contents (T newStudent) {
            player_ = newStudent;
        }
        
        template<typename T>
        void Node<T>::set_next_node (Node<T>* nextNode) {
            nextNode_ = nextNode;
        }
        
//added to make program function just for strings    
template class Node<string>;