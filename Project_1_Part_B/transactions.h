//Transactions Class
//Holds data and functions regarding the credit card transactions
/*
    cc_number_ - holds the credit card number of the transaction
    date_ - holds the date that the transaction occurred
    transaction_num_ - holds a unique identifier for the specific transaction
    vendor_ - holds the name of the vendor where the transaction occurred
    purchase_amt_ - the amount of money used in the transaction
    decline_reason_ - the reason (if any) that the card was denied
    [0 - not declined, 1 - did not pass luhn check, 2 - denied because credit limit hit]
*/

#ifndef transactions_h
#define transactions_h

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Transactions {
    private:
        string cc_number_,
               date_,
               transaction_num_,
               vendor_;
        double purchase_amt_;
        int decline_reason_;
             
    public:
        //constructor
        Transactions ();
        
        //overloaded constructor
        Transactions (string cc_number, string date, string transaction_num, string vendor, double purchase_amt) {
            cc_number_ = cc_number;
            date_ = date;
            transaction_num_ = transaction_num;
            vendor_ = vendor;
            purchase_amt_ = purchase_amt;
            decline_reason_ = 0;
        }
        
        //accessors
        //return credit card number
        const string getCCNumber ();
        //return date of transaction
        const string getDate ();
        //return unique number identifier of the transaction
        const string getTransactionNum();
        //return the name of the vendor used in the transaction
        const string getVendor();
        //return the amount of money transacted
        const double getPurchaseAmt();
        //return the validation of the card
        const int getCCValidation();

        //mutators
        //set the credit card number of the transaction
        void setCCNumber (string cc_number);
        //set the date of the transaction
        void setDate (string date);
        //set the unique identifier of the transaction
        void setTransactionNum(string transaction_num);
        //set the name of the vendor used in the transaction
        void setVendor(string vendor);
        
        //set the amount of money that the purchase was for
        void setPurchaseAmt (double purchase_amt);
        
        //Checks the transaction's validity:
        /*
          1.) Luhn Algorithm
          2.) Current Balance vs Credit Limit
        */
        void setCCValidation (double current_bal, double credit_limit);
        
};

#endif