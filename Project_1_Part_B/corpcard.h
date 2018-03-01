//Corpcard derived from Credit Card
//This is the corpcard version of a credit card and holds the specific variables and values particular to that card
/*
    max_balance_ = the maximum balance allowed on the card
    rebate_rate_ = the bonus percentage that gets returned as cash back
    rebate_total_ = the total amount of bonus held on the card for the reporting period (the month)
    overdraft_value_ = the amount that the card can be overdrafted
    limit_block_ = a boolean that holds whether or not the card can be overdrafted or not (0 = no, 1 = yes)
*/

#ifndef corpcard_h
#define corpcard_h

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "transactions.h"
#include "creditcard.h"

using namespace std;

class CorpCard: public CreditCard { 
    private:  
        double max_balance_, 
               rebate_rate_,
               rebate_total_; 
        int overdraft_value_; 
        bool limit_block_;
        string output_str;

    public:  
        //constructor
        CorpCard (); 
        
        //overloaded constructor
        CorpCard (string cc_number, string cardholder_name, double balance) : CreditCard (cc_number, cardholder_name, balance) {
            max_balance_ = 10000.00; 
            limit_block_ = false;
            overdraft_value_ = 5000;
            rebate_rate_ = .05; 
            rebate_total_ = 0;
            string output_str = "";
        }
        
        //accessors
        //returns the maximum balance the card can hold
        const double getMaxBalance();
        //returns the rebate rate
        const double getRebateRate();
        //returns the amount that the card can be overdrafted
        const int getOverdraftValue ();
        //returns whether the card can be overdrafted or not
        const bool getLimitBlock();
        //returns the total rebate value
        const double getRebateTotal();
        
        //mutators
        //sets the maximum balance on the card
        void setMaxBalance(double max_balance);
        //sets the rebate rate on the card
        void setRebateRate(double rebate_rate);
        //sets the overdraft value of the card
        void setOverdraftValue (int overdraft_value);
        //sets whether the card can be overdrawn or not
        void setLimitBlock(bool limit_block);
        //sets the total amount of rebate on the card
        void setRebateTotal (double purchase);
        
        //set the balance on the card - overloaded version of function from parent class
        //holds logic to determine if card can process amount
        void setBalance(double balance, double purchase_amt);
        
        //add output
        void addOutput (string trans_info);
        //return output
        const string getOutput ();
}; 


#endif