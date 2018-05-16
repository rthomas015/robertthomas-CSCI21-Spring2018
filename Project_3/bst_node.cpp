#include "bst_node.h"

using namespace std;

        BSTNode::BSTNode () {
            left = NULL;
            right = NULL;
        }
        
        BSTNode::BSTNode (string word, unsigned int freq) {
            left = NULL;
            right = NULL;
            wordObj_.setFreq(freq);
            wordObj_.setWord(word);
        }
        
        BSTNode::BSTNode (word aWord) {
            left = NULL;
            right = NULL;
            wordObj_ = aWord;
        }
        
        word BSTNode::get_Obj () const {
            return wordObj_;
        }
        
        string BSTNode::get_Word () const {
            return wordObj_.getWord();
        }
        
        unsigned int BSTNode::get_Freq() const {
            return wordObj_.getFreq();
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
        
        void BSTNode::set_Word (string word) {
            wordObj_.setWord(word);
        }
        
        void BSTNode::set_Freq (unsigned int freq) {
            wordObj_.setFreq(freq);
        }
        
        void BSTNode::set_Obj (word aWord) {
            wordObj_ = aWord;
        }