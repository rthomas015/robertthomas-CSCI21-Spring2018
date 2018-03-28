/*Queue
  By: Robert Thomas
  Date: 3/27/2018
  Description: This project will create a Queue, input the information from a file into it
  and then print it out one by one
*/

#include <iostream>
#include <string>
#include <fstream>
#include <queue>

using namespace std;

int main () { 
    //1. Create queue
    queue<string> theQueue;
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
    
    //5. Loop through the file and add each word to the queue
    while (!inStream.eof()) {
        //getline(inStream,word);
        inStream >> word;
        theQueue.push(word);
    }
    
    //6. Close inStream
    inStream.close();
    
    //7. Loop through queue and print
    while (!theQueue.empty()) {
      cout << theQueue.front() << endl;
      theQueue.pop();
    }
    
    return 0;
}