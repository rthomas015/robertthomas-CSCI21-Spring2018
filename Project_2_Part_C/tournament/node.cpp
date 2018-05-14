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
        Node<T>::Node(T name, Node<T>* nextNode, Node<T>* prevNode) {
            player_ = name;
            nextNode_ = nextNode;
            prevNode_ = prevNode;
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
        Node<T>* Node<T>::prev_node() const {
            return prevNode_;
        }

        template<typename T>
        void Node<T>::set_contents (T newStudent) {
            player_ = newStudent;
        }
        
        template<typename T>
        void Node<T>::set_next_node (Node<T>* nextNode) {
            nextNode_ = nextNode;
        }
        
        template<typename T>
        void Node<T>::set_prev_node (Node<T>* prevNode) {
            prevNode_ = prevNode;
        }
        
//added to make program function just for strings    
template class Node<string>;