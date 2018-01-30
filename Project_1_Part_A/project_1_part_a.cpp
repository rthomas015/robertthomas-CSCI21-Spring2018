/*Project 1 - Part A
  By: Robert Thomas
  Date: 1/25/2018 
  Description: Write a program that opens a file and receives credit card numbers from that file. Then identifies the bank issuer.
*/

//preprocessor directives
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//start of main program
int main () {
    //create file object
    ifstream cc_file;
    //create two strings, one that holds the full card number and one that holds the bankID (first six digits of the card number)
    string card_string = "", bank_ID = "";
    
    //open Credit Card file
    cc_file.open ("ccnumbers.txt");
    
    //read from file and set it to test string
    while (!cc_file.eof()) {
        getline(cc_file, card_string);
        //test by outputting the string that was just received from the file
        cout << card_string << endl;
        //set bank_ID to the first six characters in the credit card string
        bank_ID = card_string.substr(0, 6);
        
        if (bank_ID == "378282" || bank_ID == "371449") {
            //american express            
        }
        else if (bank_ID == "601111" || bank_ID == "601100") {
            //discover
        }
        else if (bank_ID == "555555" || bank_ID == "510510") {
            //mastercard
        }
        else if (bank_ID == "411111" || bank_ID == "401288" || bank_ID == "422222") {
            //visa
        }
        else {
            //error case
        }
    }
    

    // Sample Card numbers from Major Banks
    /*
        American Express	378282246310005
        American Express	371449635398431
        
        Discover	6011111111111117
        Discover	6011000990139424
        
        MasterCard	5555555555554444
        MasterCard	5105105105105100
        
        Visa	4111111111111111
        Visa	4012888888881881
        Visa	4222222222222
        Note : Even though this number has a different character count than the other test numbers, it is the correct and functional number.
    */
    

    //close file
    cc_file.close();
    return 0;
}