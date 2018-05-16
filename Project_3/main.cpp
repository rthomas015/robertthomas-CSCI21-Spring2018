/*Project 3
  By: Robert Thomas
  Date: 5/1/2018
  Description: Write a program that works similar to an autocomplete. The program
  will take a set of strings from a file, calculate their weight based on usage.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "bs_tree.h"
#include "bst_node.h"
#include "word.h"

using namespace std;

int main() {
    BSTree wordTree;
    
    //File Input
    ifstream fs;
    string file_name = "words.txt",
           temp_string = "",
           temp_word = "";
    stringstream ss;
    unsigned int temp_frequency = 0;
    
    
    fs.open(file_name.c_str());
    
    while (!fs.is_open()) {
        cout << endl << "An error occurred, please input another file: ";
        cin >> file_name;
        fs.open(file_name.c_str());
    }
  
    while (!fs.eof()) {
        getline(fs, temp_string);
        
        //parse line
        ss.clear();
        ss << temp_string;
        ss >> temp_word;
        ss >> temp_frequency;
        
        wordTree.Insert(temp_word,temp_frequency);
    }
    
    fs.close();
    //End of File Input
    
    //Print Tree in Order
    cout << "Alphabetical Order Ascending: " << wordTree.InAlphaOrder()
         << endl;
    cout << "Frequency Descending: " << wordTree.InFreqOrder();
    return 0;
}