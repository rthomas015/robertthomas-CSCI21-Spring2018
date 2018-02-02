/*Project 1 - Part A
  By: Robert Thomas
  Date: 1/25/2018 
  Description: Write a program that opens a file and receives credit card numbers from that file. Then identifies the bank issuer of each
  card: whether it is one of the four main issuers/banks or if it is not valid for the program (not one of the four).
*/

//preprocessor directives
//iostream - basic console input/output
//fstream - file stream
//string - allows usage of string data type and associated functions\
//cc_check.h - holds the credit card check function (see cc_check.cpp for more information)
#include <iostream>
#include <fstream>
#include <string>
#include "cc_check.h"

using namespace std;

//start of main program
int main () {
    //create file object and then open credit card file that holds a basic list of credit card numbers
    ifstream cc_file;
    cc_file.open ("ccnumbers.txt");
    
    //create two strings, one that holds the full card number and one that holds the bankID (first six digits of the card number)
    string card_string = "";
    
    //read from file (until the end of the file) and go line by line
    //calling cc_check
    while (!cc_file.eof()) {
        getline(cc_file, card_string);
        cc_check(card_string);
    }

    //close file
    cc_file.close();
    
    //output:
    /*
    Card Declined: 0000001234567890 --- Not from a major issuer/bank
    Card Declined: 1111111234567890 --- Not from a major issuer/bank
    Card Declined: 2222221234567890 --- Not from a major issuer/bank
    Card Declined: 3333331234567890 --- Not from a major issuer/bank
    Card Declined: 4444441234567890 --- Not from a major issuer/bank
    Accepted card: 3782821234567890 --- American Express
    Accepted card: 6011001234567890 --- Discover
    Card Declined: 1234561234567890 --- Not from a major issuer/bank
    
    */
    
    return 0;
}