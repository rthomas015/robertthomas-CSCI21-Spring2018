#include "LC3.h"


		/*
		 * Default constructor. By default, will not allow duplicates.
		 * @param newAllowDupes if true, duplicate words will be allowed
		 */
		 
	    WordList::WordList(bool newAllowDupes) {
		    allowDupes = newAllowDupes;
		}
		
		/*
		 * Add a word to the list.
		 * @param word the word to be added
		 * @return true if the word has been added, else false (duplicate words 
		 *         will not be added if allowDupes is false)
		 */
		bool WordList::addWord (string word) {
		    bool word_added = false;
		    
		    //words.size();
		    if (allowDupes == false) {
		    	//if duplicates are not allowed, test to find duplicate first
		        if (hasWord(word) == false) {
		           words.resize((words.size() + 1));
		           words.at(words.size() - 1) = word;
		           word_added = true; 
		        }
		        else {
		        	word_added = false;
		        }
		    }
		    else {
		    	//if duplicates are allowed add word automatically
		        words.resize((words.size() + 1));
		        words.at(words.size() - 1) = word;
		        word_added = true;
		    }
		    
            return word_added;
		}
		
		/*
		 * Remove all instances of a word from the list.
		 * @param word the word to be removed
		 * @return true if the word is present and removed, else false
		 */
		bool WordList::removeWord (string word) {
		    bool removed = false;
		    int num_of_words = words.size();
		    
		    for(int i=(num_of_words-1);i>=0;i--) {
		        if (words.at(i) == word) {
		           words.pop_back();
		           removed = true;
		        }
		    }
		  
		    return removed;
		}
		
		/*
		 * Check to see if a word is in the list.
		 * @param word the word to check for
		 * @return true if the word is present, else false
		 */
		bool WordList::hasWord (string word) {
		    bool has_word = false;
		    int num_of_words = words.size();
		    
		    for(int i=0;i<num_of_words;i++) {
		        if (words.at(i) == word) {
		            has_word = true;
		        }
		    }
		    return has_word;
		}

		/*
		 * Return the number of words in the list.
		 * @return an integer containing the number of words in the list
		 */

		int WordList::getWordCount () {
		    int num_of_words = words.size();
		    
		    return num_of_words;
		}

		/*
		 * Clear all of the contents of the list.
		 */
		void WordList::clear () {
            for (int i=words.size();i>=0;i--) {
            	words.pop_back();
            	words.resize(i);
            }
		}

		/*
		 * Sort the words in the list. The words will be sorted in 
		 * lexicographical order which will be case-sensitive.
		 */
		void WordList::sort () {
			//bubblesort
			int num_of_words = words.size();
			string place_holder = "";
		    
		    for(int i=0;i<num_of_words;i++) {
		    	for (int j=0;j<num_of_words-1;j++) {
		    		if (words.at(j) > words.at(j+1)) {
		    			place_holder = words.at(j);
		    			words.at(j) = words.at(j+1);
		    			words.at(j+1) = place_holder;
		    		}
		    	} 
		    }
		    
		    
		}

		/*
		 * Load the contents of a file into the list. Assumes that the file 
		 * has one word per line. Will NOT clear the current contents of the 
		 * list.
		 * @param filename the name of the file to load
		 * @return true if the file is successfully processed, else false
		 */
		bool WordList::loadFile (string filename) {
		    ifstream file;
		    bool added = false;
		    file.open(filename.c_str());
		    
		    if (!file.is_open()) {
    			return added;
			}
		    else {
		    	string list = "";

		    	while (!file.eof()) {
		        	getline(file, list);
		        	addWord(list);
		        	added = true;
		    	}
		    
		    	file.close();
		    }

		    return added;
		    
		}

		/*
		 * Return a string representation of the word list. String will contain 
		 * a numbered list, one word per line.
		 *
		 * EXAMPLE:
		 *
		 * [1] apple
		 * [2] grapefruit
		 * [3] orange
		 *
		 * @return a string representation of the word list
		 */
		string WordList::toString () {
		    stringstream ss;
		    int num_of_words = words.size();
		    
		    if (num_of_words > 0) {
		    	for(int i=0;i<num_of_words;i++) {
                	ss << "[" << (i+1) << "] " << words.at(i) << "\n";
		    	}
		    }
		    
		    return ss.str();
		}