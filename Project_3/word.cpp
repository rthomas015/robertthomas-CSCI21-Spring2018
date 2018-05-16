#include "word.h"

        word::word () {
            word_ = "";
            freq_ = 0;
        }
        
        word::word (string word, unsigned int freq) {
            word_ = word;
            freq_ = freq;
        }
        
        //getters
        string word::getWord() const {
            return word_;
        }
        
        unsigned int word::getFreq() const {
            return freq_;
        }
        
        void word::setWord(string word) {
            word_ = word;
        }
        
        void word::setFreq(unsigned int freq) {
            freq_ = freq;
        }