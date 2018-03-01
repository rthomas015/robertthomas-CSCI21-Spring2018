//Class CreditCard
//A base class that functions as a generic version of a credit card that derived classes can build upon
/*
    cc_number = holds credit card number
    cardholder_name_ = holds card holder's name
    balance_ = holds the current card balance
    vector<Transactions> account_transactions = this is where the transactions would be held internally by the
    credit card class, but i can't get it to actually function
*/

#ifndef creditcard_h
#define creditcard_h

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class CreditCard {
    private:
        string cc_number_,
               cardholder_name_;
        double balance_;
        vector<Transactions> account_transactions;
        
    public:
        //default constructor
        CreditCard ();
        
        //overloaded constructor
        CreditCard(string cc_number, string cardholder_name, double balance) {
            cc_number_ = cc_number;
            cardholder_name_ = cardholder_name;
            balance_ = balance;
        }
        
        //Mutators
        //Set the credit card's current balance
        void setBalance(double balance);
        //Set the credit card holders name
        void setCardholderName(string name);
        //Set the credit card number
        void setCCNumber(string CCNumber);

        //Accessors
        //Return the balance of the card
        const double getBalance();
        //return the cardholder's name
        string getCardholderName();
        //return the credit card number
        string getCCNumber();
        
        //function that adds the transaction to the vector of transaction objects that the class would hold
        //Note this works to add them to the vector, but the vector object does not seem to persist
        void addTransaction (string cc_number,string date,string transaction_num,string vendor,double purchase_amt);
    
};

#endif