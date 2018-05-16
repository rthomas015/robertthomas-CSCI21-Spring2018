#ifndef word_h
#define word_h

#include <iostream>
#include <string>

using namespace std;

class word {
    private:
        string word_;
        unsigned int freq_;
    
    public:
        //constructor
        //@param - none
        //@return - none
        word ();
        
        //overloaded constructor
        //@param - string word - the word in question
        //@param - freq - the frequency of the word's usage
        //@return - none
        word (string word, unsigned int freq);
        
        //getters
        //@param - none
        //@return - the word held in the class
        string getWord() const;
        
        //@param - none
        //@return - the frequency of the word
        unsigned int getFreq() const;
        
        //setters
        //@param - string word - word to set
        //@return - none
        void setWord(string word);
        
        //@param - frequency - the frequency of the word
        //@return - none
        void setFreq(unsigned int freq);
        
};

#endif