//Corpcard derived from Credit Card
//This is the corpcard version of a credit card and holds the specific variables and values particular to that card
/*
    max_balance_ = the maximum balance allowed on the card
    rebate_rate_ = the bonus percentage that gets returned as cash back
    rebate_total_ = the total amount of bonus held on the card for the reporting period (the month)
    overdraft_value_ = the amount that the card can be overdrafted
    limit_block_ = a boolean that holds whether or not the card can be overdrafted or not (0 = no, 1 = yes)
*/
#include "corpcard.h"


        //constructor
        CorpCard::CorpCard () { 
            max_balance_ = 10000.00; 
            limit_block_ = false;
            overdraft_value_ = 5000;
            rebate_rate_ = .05; 
            rebate_total_ = 0;
            string output_str = "";
        } 
        
        //accessors
        //returns the maximum balance the card can hold
        const double CorpCard::getMaxBalance() {
            return max_balance_;
        }
        //returns the rebate rate
        const double CorpCard::getRebateRate() {
            return rebate_rate_;
        }
        //returns the amount that the card can be overdrafted
        const int CorpCard::getOverdraftValue () {
            return overdraft_value_;
        }
        //returns whether the card can be overdrafted or not
        const bool CorpCard::getLimitBlock() {
            return limit_block_;   
        }
        //returns the total rebate value
        const double CorpCard::getRebateTotal() {
            return rebate_total_;
        }
        
        //mutators
        //sets the maximum balance on the card
        void CorpCard::setMaxBalance(double max_balance) {
            max_balance_ = max_balance;
        }
        //sets the rebate rate on the card
        void CorpCard::setRebateRate(double rebate_rate) {
            rebate_rate_ = rebate_rate;
        }
        //sets the overdraft value of the card
        void CorpCard::setOverdraftValue (int overdraft_value) {
            overdraft_value_ = overdraft_value;
        }
        //sets whether the card can be overdrawn or not
        void CorpCard::setLimitBlock(bool limit_block) {
            limit_block_ = limit_block;   
        }
        //sets the total amount of rebate on the card
        void CorpCard::setRebateTotal (double purchase) {
            rebate_total_ = rebate_total_ + (purchase * getRebateRate());
        }
        
        //set the balance on the card - overloaded version of function from parent class
        //holds logic to determine if card can process amount
        void CorpCard::setBalance(double balance, double purchase_amt) {
            double temp_balance = balance + purchase_amt;

            if (temp_balance < max_balance_) {
                CreditCard::setBalance(temp_balance);
            }
            else if ((temp_balance > max_balance_) && (limit_block_ == true)) {
                    //dont change balance if its over the credit limit and the limit block is activated 
            }
            else if ((temp_balance > max_balance_) && (limit_block_ == false)) {
                    //limit_block is off and you can issue warning
                    
                    addOutput("***WARNING OVERDRAFT***");
                    //then calculate balance if its still within proper range balance is less than current balance plus overdraft value
                    if (temp_balance < (max_balance_ + overdraft_value_)) {
                        CreditCard::setBalance(temp_balance);
                    }
                    //otherwise do nothing
            }
            else {
                CreditCard::setBalance(temp_balance);
            }
        }
        
        //add output
        void CorpCard::addOutput (string trans_info) {
            output_str = output_str + trans_info;
        }
        //return output
        const string CorpCard::getOutput () {
            return output_str;
        }