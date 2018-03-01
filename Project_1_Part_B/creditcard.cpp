//Class CreditCard
//A base class that functions as a generic version of a credit card that derived classes can build upon
/*
    cc_number = holds credit card number
    cardholder_name_ = holds card holder's name
    balance_ = holds the current card balance
    vector<Transactions> account_transactions = this is where the transactions would be held internally by the
    credit card class, but i can't get it to actually function
*/

#include "transactions.h"
#include "creditcard.h"

        //default constructor
        CreditCard::CreditCard () {
            cc_number_ = "";
            cardholder_name_ = "";
            balance_ = 0.0;
        }
        
        //overloaded constructor

        
        //Mutators
        //Set the credit card's current balance
        void CreditCard::setBalance(double balance) { 
            balance_ = balance; 
        } 
        //Set the credit card holders name
        void CreditCard::setCardholderName(string name) { 
            cardholder_name_ = name; 
        }
        //Set the credit card number
        void CreditCard::setCCNumber(string CCNumber) { 
            cc_number_ = CCNumber; 
        } 

        //Accessors
        //Return the balance of the card
        const double CreditCard::getBalance() { 
            return balance_; 
        }
        //return the cardholder's name
        string CreditCard::getCardholderName() { 
            return cardholder_name_; 
        }
        //return the credit card number
        string CreditCard::getCCNumber() { 
          return cc_number_;
        } 
        
        //function that adds the transaction to the vector of transaction objects that the class would hold
        //Note this works to add them to the vector, but the vector object does not seem to persist
        void CreditCard::addTransaction (string cc_number,string date,string transaction_num,string vendor,double purchase_amt) {
            stringstream ss;
            
            //adds to vector
            Transactions new_transaction (cc_number,date,transaction_num,vendor,purchase_amt);
            account_transactions.push_back(new_transaction);
            
            //adds to output string stream (this is also unable to persist)
            ss << "Transaction ID#: " << new_transaction.getTransactionNum()
                     << " Date:" << new_transaction.getDate() << " $" 
                     << new_transaction.getPurchaseAmt() << endl;
                     
        }
