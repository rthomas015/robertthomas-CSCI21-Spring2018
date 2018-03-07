/*
 * Name        : lab_7.cpp
 * Author      : FILL IN
 * Description : Working with File I/O
 */
#include "lab_7.h"

using namespace std;

void ProcessArguments(int argc, char* argv[]) {
        string temp_string = "";
        
        for (int i=1;i<argc;i++) {   
            temp_string = argv[i];
            
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
}
