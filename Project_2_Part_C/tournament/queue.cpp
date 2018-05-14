#include "queue.h"

    template <typename T>
    Queue<T>::Queue () {
        head = NULL;
        tail = NULL;
    }
    
    template <typename T>
    void Queue<T>::push(T info) {
        //pushes into new tail
        Node<T>* newNode = new Node<T>;
        newNode->set_contents(info);
        
        if (tail == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            Node<T>* tempPtr = new Node<T>;
            tempPtr = tail;
            tail->set_prev_node(newNode);
            tail = newNode;
            tail->set_next_node(tempPtr);
        }
        
    }

    template <typename T>
    void Queue<T>::pop() {
        Node<T>* ptr = tail;
        Node<T>* penultimateptr = new Node<T>();
        
        if (tail != NULL) {
            if (tail->next_node() == NULL) {
                head = NULL;
                tail = NULL;
            }
        
            else {
                while (ptr->next_node()) {
                    penultimateptr = ptr;
                    ptr = ptr->next_node();
                }
                ptr = NULL;
                penultimateptr->set_next_node(ptr);
                head = penultimateptr;
            }
        }
    }
    
    template <typename T>
    string Queue<T>::print() {
        //Prints first to last
        stringstream ss;
        Node<T>* ptr = tail;
        
        while (ptr != NULL) {
            ss << ptr->contents() << " ";
            ptr = ptr->next_node();
        }
        
        return ss.str();
    }
    
    template <typename T>
    T Queue<T>::peek_name() {
        return head->contents();
    }
    
    template <typename T>
    int Queue<T>::size() {
        int contents = 0;
        Node<T>* ptr = tail;
        
        while (ptr != NULL) {
            contents = contents + 1;
            ptr = ptr->next_node();
        }
        
        return contents;
    }
    
    template <typename T>
    Iterator<T> Queue<T>::end() {
        Iterator<T> iter;
        return iter;
    }
        
    template <typename T>
    Iterator<T> Queue<T>::begin() {
        Iterator<T> iter(tail);
        
        return iter;
    }
    
    template <typename T>
    Iterator<T> Queue<T>::rbegin() {
        Iterator<T> iter(head);
        return iter;
    }


//added to make program function just for strings   
template class Queue<string>;