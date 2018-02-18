/**********************************************/
/***** Programming Challenge 3       SPEC *****/
/**********************************************/
#ifndef LC3_H
#define LC3_H

#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

using std::ifstream;
using std::ostringstream;
using std::sort;
using std::string;
using std::vector;

class WordList {
	public:


		WordList(bool newAllowDupes=false); 

		bool addWord (string word);
		
		bool removeWord (string word);
		
		bool hasWord (string word);

		int getWordCount ();

		void clear ();

		void sort ();

		bool loadFile (string filename);

		string toString ();

	private:
		vector<string> words;
		bool allowDupes;
};

#endif