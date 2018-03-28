#include <iostream>
#include <string>
#include <fstream>
#include <stack>

using namespace std;

int main () { 
    //1. Create stack
    stack<string> theStack;
    string inFileName = "",
           word = "";
           
    //2. Display Prompt    
    cout << "Input a file name: ";
    
    //3. Read in File Name
    cin >> inFileName;
    
    //4-A. Open file stream
    ifstream inStream;
    inStream.open (inFileName.c_str());
      
    //4-B. Test file is open properly
    while (!inStream.is_open()) {
        cout << endl << "An error occurred, please input another file: ";
        cin >> inFileName;
        inStream.open(inFileName.c_str());
    }
    
    //5. Loop through the file and add each word to the stack
    while (!inStream.eof()) {
        //getline(inStream,word);
        inStream >> word;
        theStack.push(word);
    }
    
    //6. Close inStream
    inStream.close();
    
    //7. Loop through stack and print
    while (!theStack.empty()) {
      cout << theStack.top() << endl;
      theStack.pop();
    }
    
    return 0;
}