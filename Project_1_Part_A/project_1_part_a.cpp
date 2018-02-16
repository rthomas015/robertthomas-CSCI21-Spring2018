/*Project 1 - Part A
  By: Robert Thomas
  Date: 1/25/2018 
  Description: Write a program that opens a file and receives credit card numbers from that file. Then identifies the bank issuer of each
  card: whether it is one of the four main issuers/banks or if it is not valid for the program (not one of the four).
*/

//preprocessor directives
//iostream - basic console input/output
//fstream - file stream
//string - allows usage of string data type and associated functions
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//start of main program
int main () {
    //create file object and then open credit card file that holds a basic list of credit card numbers
    ifstream cc_file;
    cc_file.open ("ccnumbers.txt");
    
    //create two strings, one that holds the full card number and one that holds the bankID (first six digits of the card number)
    string card_string = "", bank_ID = "";
    
    //read from file (until the end of the file) and go line by line
    while (!cc_file.eof()) {
        getline(cc_file, card_string);
        //set bank_ID to the first six characters in the credit card string
        bank_ID = card_string.substr(0, 6);
        
        //test each card for a valid BIN (6 digits) 
        if ((bank_ID.substr(0,2) == "34" || bank_ID.substr(0,2) == "37") && card_string.length() == 15) {
            //american express
            cout << "Accepted card: " << card_string << " --- American Express" << endl;
        }
        else if (((bank_ID.substr(0,4) == "6011") || (bank_ID.substr(0,3) >= "644" && bank_ID.substr(0,3) <= "649") || (bank_ID >= "622126" && bank_ID <= "622925") || (bank_ID.substr(0,2) == "65")) && card_string.length() == 16) {
            //discover
            cout << "Accepted card: " << card_string << " --- Discover" << endl;
        }
        else if ((bank_ID.substr(0,2) >= "51" && bank_ID.substr(0,2) <= "55") && card_string.length() == 16) {
            //mastercard
            cout << "Accepted card: " << card_string << " --- MasterCard" << endl;
        }
        else if ((bank_ID.substr(0,1) == "4") && (card_string.length() >= 13 && card_string.length() <= 16)) {
            //visa
            cout << "Accepted card: " << card_string << " --- Visa" << endl;
        }
        else {
            //error case (card BIN not recognized)
            cout << "Card Declined: " << card_string << " --- Not from a major issuer/bank" << endl;
        }
    }
    

    // Sample Card numbers from Major Banks based off blog post (6 digits is the BIN)
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
    
    //output:
    /*

Card Declined: 0000001234567890 --- Not from a major issuer/bank
Card Declined: 1111111234567890 --- Not from a major issuer/bank
Card Declined: 2222221234567890 --- Not from a major issuer/bank
Card Declined: 3333331234567890 --- Not from a major issuer/bank
Accepted card: 4444441234567890 --- Visa
Accepted card: 3782821234567890 --- American Express
Accepted card: 6011001234567890 --- Discover
Card Declined: 1234561234567890 --- Not from a major issuer/bank
Accepted card: 3400000000000000 --- American Express
Accepted card: 3422222222222222 --- American Express
Accepted card: 3477777777777777 --- American Express
Accepted card: 5144444444444444 --- MasterCard
Accepted card: 5222222222222222 --- MasterCard
Accepted card: 5333333333333333 --- MasterCard
Card Declined: 5777777777777777 --- Not from a major issuer/bank
    
    */
    
    return 0;
}