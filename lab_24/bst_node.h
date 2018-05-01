#ifndef bst_node_h
#define bst_node_h

#include <iostream>
#include <string>

using namespace std;

class BSTNode {
    private:
        BSTNode* left;
        BSTNode* right;
        int content;
       
    public:
        BSTNode ();
        
        BSTNode (int x);
        
        int contents () const;
        
        BSTNode* left_child () const;
        
        BSTNode* right_child() const;
        
        void set_left_child(BSTNode* node);
        
        void set_right_child(BSTNode* node);
        
        void set_contents (int x);
        
};

#endif