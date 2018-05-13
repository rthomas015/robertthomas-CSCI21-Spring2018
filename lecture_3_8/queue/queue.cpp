#include "queue.h"

    Queue::Queue () {
        head = NULL;
        tail = NULL;
    }

    Queue::~Queue() {
        Node* ptr = head;
       
        while(ptr != 0 ) {
            Node* next = ptr->next_node();
            delete ptr;
            ptr = next;
        }
    
    }
    
    void Queue::push(string info) {
        //pushes into new tail
        Node* newNode = new Node();
        newNode->set_contents(info);
        
        if (tail == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->set_next_node(tail);
            tail = newNode;
        }
        
    }
    
    void Queue::pop() {
        Node* ptr = tail;
        Node* penultimateptr = new Node();
        
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
    
    
    string Queue::print() {
        //Prints first to last
        stringstream ss;
        Node* ptr = tail;
        
        while (ptr != NULL) {
            ss << ptr->contents() << " ";
            ptr = ptr->next_node();
        }
        
        return ss.str();
    }

    string Queue::peek() {
        return head->contents();
    }

    int Queue::size() {
        int contents = 0;
        Node* ptr = tail;
        
        while (ptr != NULL) {
            contents = contents + 1;
            ptr = ptr->next_node();
        }
        
        return contents;
    }