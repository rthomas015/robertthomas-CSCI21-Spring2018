#ifndef bs_tree_H
#define bs_tree_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "bst_node.h"
#include "word.h"

using namespace std;

class BSTree {
    private:
        BSTNode* root;
        
    public:
        BSTree();
        int size();
        string InAlphaOrder();
        string RecursiveAlphaInOrder(BSTNode* aNode);
        
        string InFreqOrder();
        string RecursiveFreqInOrder(BSTNode* aNode);
        
        unsigned int FindMinFreq();
        
        int RecursiveSize(BSTNode* aNode);
        
        bool Remove(string aWord);
        bool RecursiveRemove(string aWord);
        
        bool Insert(string aWord, unsigned int aFreq);
        
        void Clear();
        
        //int recursiveOrder(BSTNode* currentNode, int minimum);
        
        //BSTNode* findLocation(BSTNode* currentNode, int minimum);
        
        //BSTNode* recursivelyFindMinimum(BSTNode* currentNode, int minimum);
    


};

#endif