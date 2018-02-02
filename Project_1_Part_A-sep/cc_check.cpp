#include <iostream>
#include <string>
#include "cc_check.h"

using namespace std;

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

//Function: cc_check
//Accepts a credit card number in the form of a string, takes the first six digits or the BIN (bank_ID) and
//tests the number to determine which bank issuer issued the card, or if the card is not one of the four major issuers (visa, mastercard
// discover, american express) it rejects the card
//@param card_string = credit card number

void cc_check (string card_string) {

        //set bank_ID to the first six characters in the credit card string
        string bank_ID = card_string.substr(0, 6);
        
        //test each card for a valid BIN (6 digits) 
        if (bank_ID == "378282" || bank_ID == "371449") {
            //american express
            cout << "Accepted card: " << card_string << " --- American Express" << endl;
        }
        else if (bank_ID == "601111" || bank_ID == "601100") {
            //discover
            cout << "Accepted card: " << card_string << " --- Discover" << endl;
        }
        else if (bank_ID == "555555" || bank_ID == "510510") {
            //mastercard
            cout << "Accepted card: " << card_string << " --- MasterCard" << endl;
        }
        else if (bank_ID == "411111" || bank_ID == "401288" || bank_ID == "422222") {
            //visa
            cout << "Accepted card: " << card_string << " --- Visa" << endl;
        }
        else {
            //error case (card BIN not recognized)
            cout << "Card Declined: " << card_string << " --- Not from a major issuer/bank" << endl;
        }
        
}