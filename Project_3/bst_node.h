#ifndef bst_node_h
#define bst_node_h

#include <iostream>
#include <string>
#include "word.h"

using namespace std;

class BSTNode {
    private:
        BSTNode* left;
        BSTNode* right;
        word wordObj_;
       
    public:
        BSTNode ();
        
        BSTNode (string word, unsigned int freq);
        
        BSTNode (word aWord);
        
        
        //getters
        word get_Obj () const;
        
        string get_Word () const;
        
        unsigned int get_Freq() const;
        
        BSTNode* left_child () const;
        
        BSTNode* right_child() const;
        
        
        //setters
        void set_left_child(BSTNode* node);
        
        void set_right_child(BSTNode* node);
        
        void set_Word (string word);
        
        void set_Freq (unsigned int freq);
        
        void set_Obj (word aWord);
        
};

#endif