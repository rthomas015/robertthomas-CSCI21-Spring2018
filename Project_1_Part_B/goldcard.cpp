//GoldCard derived from Credit Card
//This is the goldcard version of a credit card and holds the specific variables and values particular to that card
/*
    max_balance_ = the maximum balance allowed on the card
    rebate_rate_ = the bonus percentage that gets returned as cash back
    rebate_total_ = the total amount of bonus held on the card for the reporting period (the month)
    overdraft_value_ = the amount that the card can be overdrafted
    limit_block_ = a boolean that holds whether or not the card can be overdrafted or not (0 = no, 1 = yes)
    output_str = a string that holds the transaction data in lieu of the vector<Transactions> from the credit card class
*/

#include "transactions.h"
#include "creditcard.h"
#include "goldcard.h"

        //constructor
        GoldCard::GoldCard () {
            max_balance_ = 3000.00; 
            limit_block_ = true;
            overdraft_value_ = 0;
            rebate_rate_ = .01;
            rebate_total_ = 0.0;
            output_str = "";
        } 
        
        //accessors
        //returns the maximum balance the card can hold
        const double GoldCard::getMaxBalance() {
            return max_balance_;
        }
        //returns the rebate rate
        const double GoldCard::getRebateRate() {
            return rebate_rate_;
        }
        //returns the amount that the card can be overdrafted
        const int GoldCard::getOverdraftValue () {
            return overdraft_value_;
        }
        //returns whether the card can be overdrafted or not
        const bool GoldCard::getLimitBlock() {
            return limit_block_;   
        }
        //returns the total rebate value
        const double GoldCard::getRebateTotal() {
            return rebate_total_;
        }
        
        //mutators
        //sets the maximum balance on the card
        void GoldCard::setMaxBalance(double max_balance) {
            max_balance_ = max_balance;
        }
        //sets the rebate rate on the card
        void GoldCard::setRebateRate(double rebate_rate) {
            rebate_rate_ = rebate_rate;
        }
        //sets the overdraft value of the card
        void GoldCard::setOverdraftValue (int overdraft_value) {
            overdraft_value_ = overdraft_value;
        }
        //sets whether the card can be overdrawn or not
        void GoldCard::setLimitBlock(bool limit_block) {
            limit_block_ = limit_block;   
        }
        //sets the total amount of rebate on the card
        void GoldCard::setRebateTotal (double purchase) {
            rebate_total_ = rebate_total_ + (purchase * getRebateRate());
        }
        
        //set the balance on the card - overloaded version of function from parent class
        //holds logic to determine if card can process amount
        void GoldCard::setBalance(double balance, double purchase_amt) {
            double temp_balance = balance + purchase_amt;
            
            if ((temp_balance > max_balance_) && (limit_block_ == true)) {
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
        void GoldCard::addOutput (string trans_info) {
            output_str = output_str + trans_info;
        }
        //return output
        const string GoldCard::getOutput () {
            return output_str;
        }
