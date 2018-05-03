#include "bst_node.h"

using namespace std;

        BSTNode::BSTNode () {
            left = NULL;
            right = NULL;
            content = 0;
        }
        
        BSTNode::BSTNode (int x) {
            left = NULL;
            right = NULL;
            content = x;
        }
        
        int BSTNode::contents () const {
            return content;
        }
        
        BSTNode* BSTNode::left_child () const {
            return left;
        }
        
        BSTNode* BSTNode::right_child() const {
            return right;
        }
        
        void BSTNode::set_left_child(BSTNode* node) {
            left = node;
        }
        
        void BSTNode::set_right_child(BSTNode* node) {
            right = node;
        }
        
        void BSTNode::set_contents (int x) {
            content = x;
        }
        