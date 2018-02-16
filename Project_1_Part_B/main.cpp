/*Project 1 - Part B
  By: Robert Thomas
  Date: 2/06/2018 
  Description: 
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class CreditCard {
    private:
        string cc_number_,
               cardholder_name_;
        double balance_;
    
    public:
        //constructor
        //CreditCard(int cc_num) {
        //    cc_number_ = cc_num; 
        //}
        
        void setBalance(double balance) { 
            balance_ = balance; 
        } 
        
        const double getBalance() { 
            return balance_; 
        } 

        void setcardholder_name(string name) { 
            cardholder_name_ = name; 
        }

        string getcardholder_name() { 
            return cardholder_name_; 
        }

        void setcc_number(string CCNumber) { 
            cc_number_ = CCNumber; 
        } 

        string getcc_number() { 
          return cc_number_; 
        } 

        //use luhn algorithm 

        const bool Validate () { 
            bool valid = false;
            
            return valid;
        }
        
};

//Create three subclasses of each card type 

class GoldCard: public CreditCard { 
    private:  
        double max_balance_, 
               rebate_rate_; 
        int overdraft_value_; 
        bool limit_block_; 
    
    public:  
        GoldCard () {
            max_balance_ = 3000; 
            limit_block_ = true;
            overdraft_value_ = 0;
            rebate_rate_ = .01; 
        } 
}; 

class PlatCard: public CreditCard { 
    private:  
        double max_balance_, 
               rebate_rate_; 
        int overdraft_value_; 
        bool limit_block_; 

    public:  
        PlatCard () { 
            max_balance_ = 3000; 
            limit_block_ = true; 
            overdraft_value_ = 1000;
            rebate_rate_ = .02; 
        }
}; 

class CorpCard: public CreditCard { 
    private:  
        double max_balance_, 
               rebate_rate_; 
        int overdraft_value_; 
        bool limit_block_; 

    public:  
        CorpCard () { 
            max_balance_ = 10000; 
            limit_block_ = true;
            overdraft_value_ = 5000;
            rebate_rate_ = .05; 
        } 
}; 

int main () {
    ifstream transactions,
             cc_data;
    string temp_string = "";

    //test two cards for now
    //CreditCard card;
    string cc_number_ = "",
        cardholder_name_ = "";
        double balance_ = 0.0; 
    string type_of_card = "",
            bal = "";
    
    transactions.open("transactions.txt");
    cc_data.open ("cc_data.txt");
    
    //read in from cc_data
    while (!cc_data.eof()) {
        getline(cc_data, temp_string);
        //parse line
        cc_number_ = temp_string.substr(0,temp_string.find_first_of(" "));
        cardholder_name_ = temp_string.substr(cc_number_.size()+1,temp_string.find_first_of(" ")-1);
        type_of_card = temp_string.substr(cc_number_.size()+cardholder_name_.size()+1,4);
        bal = temp_string.substr(cc_number_.size()+cardholder_name_.size()+type_of_card.size()+1,temp_string.size()-1);
        //balance_ = temp_string.substr(cc_number_.size()+cardholder_name_.size()+1,temp_string.find_first_of(" "));
        //new CreditCard = card("asdf");
    }
    cout << cc_number_ << endl << cardholder_name_ << endl << type_of_card << endl << bal;
    //read in from transactions
    while (!transactions.eof()) {
        getline(transactions, temp_string);
    }
    
    transactions.close();
    cc_data.close();
    
    return 0;
}