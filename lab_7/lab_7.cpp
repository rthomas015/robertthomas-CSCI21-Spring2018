/*
 * Name        : lab_7.cpp
 * Author      : FILL IN
 * Description : Working with File I/O
 */
#include "lab_7.h"

using namespace std;

/*
 * Open and read the contents of a text file. Each line of the
 * file will contain a single integer of possible values 10, 20,
 * 30, 40, or 50. Perform the following operations on the input values:
 *   10 -- invoke the function OnTen
 *   20 -- invoke the function OnTwenty
 *   30 -- invoke the function OnThirty
 *   40 -- invoke the function OnForty
 *   50 -- invoke the function OnFifty
 *   any other value -- invoke the function OnError
 * DON'T FORGET TO CLOSE YOUR FILE BEFORE YOUR FUNCTION ENDS!!!
 * @param string filename - A string containing the name of the file to
 *                          be processed
 * @return bool - True if filename was successfully opened and processed,
 *                else false
 */
bool ProcessFile(string filename) {
    bool success = false;
    string temp_string = "";
    fstream input_file;
    input_file.open(filename.c_str());
    
    if (input_file.is_open()) {
        while (!input_file.eof()) {
            getline(input_file, temp_string);
            
            if (temp_string == "10") {
                OnTen();
            }
            else if (temp_string == "20") {
                OnTwenty();
            }
            else if (temp_string == "30") {
                OnThirty();
            }
            else if (temp_string == "40") {
                OnForty();
            }
            else if (temp_string == "50") {
                OnFifty();
            }
            else {
                OnError();
            }
        }
        
        success = true;
    }
    else {
        return false;
    } 

    input_file.close();
    return success;
}