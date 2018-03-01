/*Project 1 - Part B
  By: Robert Thomas
  Date: 2/06/2018 
  Description: This project will open two files one a document with transaction data in it
  (card number, date, purchase number, vendor/business, balance) and another with credit card
  data in it (card number, credit card holder name, current balance, and type of card:
  platinum, gold, corporate) and read this information into arrays. Then will validate
  the transaction by using the Luhn Algorithm to make sure the card is correct, then make sure
  there is enough of a balance on the card to accomodate the purchase
*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;


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
        Transactions () {
            cc_number_ = "";
            date_ = "";
            transaction_num_ = "";
            vendor_ = "";
            purchase_amt_ = 0.0;
            decline_reason_ = 0;
        }
        
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
        const string getCCNumber () {
            return cc_number_;
        }
        //return date of transaction
        const string getDate () {
            return date_;
        }
        //return unique number identifier of the transaction
        const string getTransactionNum() {
            return transaction_num_;
        }
        //return the name of the vendor used in the transaction
        const string getVendor() {
            return vendor_;
        }
        //return the amount of money transacted
        const double getPurchaseAmt() {
            return purchase_amt_;
        }
        //return the validation of the card
        const int getCCValidation() {
            return decline_reason_;
        }

        //mutators
        //set the credit card number of the transaction
        void setCCNumber (string cc_number) {
            cc_number_ = cc_number;
        }
        //set the date of the transaction
        void setDate (string date) {
            date_ = date;
        }
        //set the unique identifier of the transaction
        void setTransactionNum(string transaction_num) {
            transaction_num_ = transaction_num;
        }
        //set the name of the vendor used in the transaction
        void setVendor(string vendor) {
            vendor_ = vendor;
        }
        //set the amount of money that the purchase was for
        void setPurchaseAmt (double purchase_amt) {
            purchase_amt_ = purchase_amt;
        }
        
        //Checks the transaction's validity:
        /*
          1.) Luhn Algorithm
          2.) Current Balance vs Credit Limit
        */
        void setCCValidation (double current_bal, double credit_limit) {
            /*
                cc_number = holds the credit card number
                parity = needed because credit card numbers vary in length, it holds the size of the string mod 2
                check_bit = the last digit in the credit card number to check against
                sum = holds the sum of the digits in the card number
                temp_value = used to hold the value of the current digit being looked at
            */
            string cc_number = getCCNumber();
            int cc_size = cc_number.size();
            int parity = cc_size % 2;
            char check_bit = cc_number.at(cc_size-1);
            int temp_value = 0,
                sum = 0;
            
            //Test #1: Validation Algorithm (luhn algorithm)
            for (int i=(cc_size-2);i>=0;i--) {
                //convert from ascii to an actual integer
                temp_value = cc_number.at(i)-48;
                
                //check to see if its every other digit (starting with the number after the check bit)
                if (i % 2 == parity) {
                    temp_value = (temp_value) * 2;
                    if (temp_value > 9) {
                        temp_value = temp_value - 9;
                    }
                }
                //sum all values in the credit card number after performing the math essential to the luhn function/algorithm
                sum = sum + temp_value;
            }
            
            //change from ascii number to integer
            temp_value = check_bit-48;
            
            //test using final step of Luhn Algorithm
            if (((sum * 9) % 10) != temp_value) {
                decline_reason_ = 1;
            } //<-- end of luhn algorithm
            
            //Test #2: balance plus transaction amount vs credit limit
            else if ((current_bal + purchase_amt_) > credit_limit) {
                decline_reason_ = 2;
            }
            else {
                decline_reason_ = 0;
            }
        }
        
};

//Class CreditCard
//A base class that functions as a generic version of a credit card that derived classes can build upon
/*
    cc_number = holds credit card number
    cardholder_name_ = holds card holder's name
    balance_ = holds the current card balance
    vector<Transactions> account_transactions = this is where the transactions would be held internally by the
    credit card class, but i can't get it to actually function
*/
class CreditCard {
    private:
        string cc_number_,
               cardholder_name_;
        double balance_;
        vector<Transactions> account_transactions;
        
    public:
        //default constructor
        CreditCard () {
            cc_number_ = "";
            cardholder_name_ = "";
            balance_ = 0.0;
        }
        
        //overloaded constructor
        CreditCard(string cc_number, string cardholder_name, double balance) {
            cc_number_ = cc_number;
            cardholder_name_ = cardholder_name;
            balance_ = balance;
        }
        
        //Mutators
        //Set the credit card's current balance
        void setBalance(double balance) { 
            balance_ = balance; 
        } 
        //Set the credit card holders name
        void setCardholderName(string name) { 
            cardholder_name_ = name; 
        }
        //Set the credit card number
        void setCCNumber(string CCNumber) { 
            cc_number_ = CCNumber; 
        } 

        //Accessors
        //Return the balance of the card
        const double getBalance() { 
            return balance_; 
        }
        //return the cardholder's name
        string getCardholderName() { 
            return cardholder_name_; 
        }
        //return the credit card number
        string getCCNumber() { 
          return cc_number_;
        } 
        
        //function that adds the transaction to the vector of transaction objects that the class would hold
        //Note this works to add them to the vector, but the vector object does not seem to persist
        void addTransaction (string cc_number,string date,string transaction_num,string vendor,double purchase_amt) {
            stringstream ss;
            
            //adds to vector
            Transactions new_transaction (cc_number,date,transaction_num,vendor,purchase_amt);
            account_transactions.push_back(new_transaction);
            
            //adds to output string stream (this is also unable to persist)
            ss << "Transaction ID#: " << new_transaction.getTransactionNum()
                     << " Date:" << new_transaction.getDate() << " $" 
                     << new_transaction.getPurchaseAmt() << endl;
                     
        }
    
};

//Create three subclasses of each card type 

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
class GoldCard: public CreditCard { 
    private:  
        double max_balance_, 
               rebate_rate_,
               rebate_total_; 
        int overdraft_value_; 
        bool limit_block_;
        string output_str;
        
    public:  
        //constructor
        GoldCard () {
            max_balance_ = 3000.00; 
            limit_block_ = true;
            overdraft_value_ = 0;
            rebate_rate_ = .01;
            rebate_total_ = 0;
            output_str = "";
        } 
        
        //overloaded constructor with initialization list to pass other values to CreditCard constructor
        GoldCard (string cc_number, string cardholder_name, double balance) : CreditCard (cc_number, cardholder_name, balance) {
            max_balance_ = 3000.00; 
            limit_block_ = true;
            overdraft_value_ = 0;
            rebate_rate_ = .01; 
            rebate_total_ = 0;
            output_str = "";
        }
        
        //accessors
        //returns the maximum balance the card can hold
        const double getMaxBalance() {
            return max_balance_;
        }
        //returns the rebate rate
        const double getRebateRate() {
            return rebate_rate_;
        }
        //returns the amount that the card can be overdrafted
        const int getOverdraftValue () {
            return overdraft_value_;
        }
        //returns whether the card can be overdrafted or not
        const bool getLimitBlock() {
            return limit_block_;   
        }
        //returns the total rebate value
        const double getRebateTotal() {
            return rebate_total_;
        }
        
        //mutators
        //sets the maximum balance on the card
        void setMaxBalance(double max_balance) {
            max_balance_ = max_balance;
        }
        //sets the rebate rate on the card
        void setRebateRate(double rebate_rate) {
            rebate_rate_ = rebate_rate;
        }
        //sets the overdraft value of the card
        void setOverdraftValue (int overdraft_value) {
            overdraft_value_ = overdraft_value;
        }
        //sets whether the card can be overdrawn or not
        void setLimitBlock(bool limit_block) {
            limit_block_ = limit_block;   
        }
        //sets the total amount of rebate on the card
        void setRebateTotal (double purchase) {
            rebate_total_ = rebate_total_ + (purchase * getRebateRate());
        }
        
        //set the balance on the card - overloaded version of function from parent class
        //holds logic to determine if card can process amount
        void setBalance(double balance, double purchase_amt) {
            double temp_balance = balance + purchase_amt;
            
            if ((temp_balance > max_balance_) && (limit_block_ == true)) {
                    //dont change balance if its over the credit limit and the limit block is activated 
            }
            else if ((temp_balance > max_balance_) && (limit_block_ == false)) {
                    //limit_block is off and you can issue warning
                    output_str = output_str + "***WARNING OVERDRAFT***";
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
        void addOutput (string trans_info) {
            output_str = output_str + trans_info;
        }
        //return output
        const string getOutput () {
            return output_str;
        }

}; 

//Platcard derived from Credit Card
//This is the platcard version of a credit card and holds the specific variables and values particular to that card
/*
    max_balance_ = the maximum balance allowed on the card
    rebate_rate_ = the bonus percentage that gets returned as cash back
    rebate_total_ = the total amount of bonus held on the card for the reporting period (the month)
    overdraft_value_ = the amount that the card can be overdrafted
    limit_block_ = a boolean that holds whether or not the card can be overdrafted or not (0 = no, 1 = yes)
*/
class PlatCard: public CreditCard { 
    private:  
        double max_balance_, 
               rebate_rate_,
               rebate_total_; 
        int overdraft_value_; 
        bool limit_block_;
        string output_str;
    
    public:  
        //constructor
        PlatCard () { 
            max_balance_ = 3000.00; 
            limit_block_ = false; 
            overdraft_value_ = 1000;
            rebate_rate_ = .02;
            rebate_total_ = 0;
            output_str = "";
        }
        
        //overloaded constructor
        PlatCard (string cc_number, string cardholder_name, double balance) : CreditCard (cc_number, cardholder_name, balance) {
            max_balance_ = 3000.00; 
            limit_block_ = false;
            overdraft_value_ = 1000;
            rebate_rate_ = .02; 
            rebate_total_ = 0;
            output_str = "";
        }
        
        //accessors
        //returns the maximum balance the card can hold
        const double getMaxBalance() {
            return max_balance_;
        }
        //returns the rebate rate
        const double getRebateRate() {
            return rebate_rate_;
        }
        //returns the amount that the card can be overdrafted
        const int getOverdraftValue () {
            return overdraft_value_;
        }
        //returns whether the card can be overdrafted or not
        const bool getLimitBlock() {
            return limit_block_;   
        }
        //returns the total rebate value
        const double getRebateTotal() {
            return rebate_total_;
        }
        
        //mutators
        //sets the maximum balance on the card
        void setMaxBalance(double max_balance) {
            max_balance_ = max_balance;
        }
        //sets the rebate rate on the card
        void setRebateRate(double rebate_rate) {
            rebate_rate_ = rebate_rate;
        }
        //sets the overdraft value of the card
        void setOverdraftValue (int overdraft_value) {
            overdraft_value_ = overdraft_value;
        }
        //sets whether the card can be overdrawn or not
        void setLimitBlock(bool limit_block) {
            limit_block_ = limit_block;   
        }
        //sets the total amount of rebate on the card
        void setRebateTotal (double purchase) {
            rebate_total_ = rebate_total_ + (purchase * getRebateRate());
        }
        
        //set the balance on the card - overloaded version of function from parent class
        //holds logic to determine if card can process amount
        void setBalance(double balance, double purchase_amt) {
            double temp_balance = balance + purchase_amt;
            
            if ((temp_balance > max_balance_) && (limit_block_ == true)) {
                    //dont change balance if its over the credit limit and the limit block is activated 
            }
            else if ((temp_balance > max_balance_) && (limit_block_ == false)) {
                    //limit_block is off and you can issue warning
                    output_str = output_str + "***WARNING OVERDRAFT***";
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
        void addOutput (string trans_info) {
            output_str = output_str + trans_info;
        }
        //return output
        const string getOutput () {
            return output_str;
        }
}; 

//Corpcard derived from Credit Card
//This is the corpcard version of a credit card and holds the specific variables and values particular to that card
/*
    max_balance_ = the maximum balance allowed on the card
    rebate_rate_ = the bonus percentage that gets returned as cash back
    rebate_total_ = the total amount of bonus held on the card for the reporting period (the month)
    overdraft_value_ = the amount that the card can be overdrafted
    limit_block_ = a boolean that holds whether or not the card can be overdrafted or not (0 = no, 1 = yes)
*/
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
        CorpCard () { 
            max_balance_ = 10000.00; 
            limit_block_ = false;
            overdraft_value_ = 5000;
            rebate_rate_ = .05; 
            rebate_total_ = 0;
            string output_str = "";
        } 
        
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
        const double getMaxBalance() {
            return max_balance_;
        }
        //returns the rebate rate
        const double getRebateRate() {
            return rebate_rate_;
        }
        //returns the amount that the card can be overdrafted
        const int getOverdraftValue () {
            return overdraft_value_;
        }
        //returns whether the card can be overdrafted or not
        const bool getLimitBlock() {
            return limit_block_;   
        }
        //returns the total rebate value
        const double getRebateTotal() {
            return rebate_total_;
        }
        
        //mutators
        //sets the maximum balance on the card
        void setMaxBalance(double max_balance) {
            max_balance_ = max_balance;
        }
        //sets the rebate rate on the card
        void setRebateRate(double rebate_rate) {
            rebate_rate_ = rebate_rate;
        }
        //sets the overdraft value of the card
        void setOverdraftValue (int overdraft_value) {
            overdraft_value_ = overdraft_value;
        }
        //sets whether the card can be overdrawn or not
        void setLimitBlock(bool limit_block) {
            limit_block_ = limit_block;   
        }
        //sets the total amount of rebate on the card
        void setRebateTotal (double purchase) {
            rebate_total_ = rebate_total_ + (purchase * getRebateRate());
        }
        
        //set the balance on the card - overloaded version of function from parent class
        //holds logic to determine if card can process amount
        void setBalance(double balance, double purchase_amt) {
            double temp_balance = balance + purchase_amt;
            cout << "here I asdf";
            if (temp_balance < max_balance_) {
                CreditCard::setBalance(temp_balance);
            }
            else if ((temp_balance > max_balance_) && (limit_block_ == true)) {
                    //dont change balance if its over the credit limit and the limit block is activated 
            }
            else if ((temp_balance > max_balance_) && (limit_block_ == false)) {
                    //limit_block is off and you can issue warning
                    
                    output_str = output_str + "***WARNING OVERDRAFT***";
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
        void addOutput (string trans_info) {
            output_str = output_str + trans_info;
        }
        //return output
        const string getOutput () {
            return output_str;
        }
}; 


//start of main program
int main () {
    //Create input file stream objects for transactions and one for credit card data
    ifstream transactions,
             cc_data;
    
    //create temporary variables to hold transactions/credit card information before populating
    //appropriate credit card vector
    string cc_number = "",
           cardholder_name_first = "",
           cardholder_name_second = "",
           cardholder_name = "",
           type_of_card = "";
    double balance = 0.0,
           purchase_amt = 0.0,
           max_balance = 0.0;
    string temp_string = "";
    stringstream ss, approved, denied;
    
    denied << "List of Denied Transactions: " << endl;

    //Create three separate vectors for Gold Cards, Platinum Cards and Corporate Cards
    vector<GoldCard> golds;
    vector<PlatCard> plats;
    vector<CorpCard> corps;
    
    //Create vector of transaction objects
    vector<Transactions> cc_transactions;
    
    //open file stream objects
    transactions.open("transactions.txt");
    cc_data.open ("cc_data.txt");
    
    //read in from credit card data file (cc_data.txt)
    while (!cc_data.eof()) {
        //get data line by line
        getline(cc_data, temp_string);
        
        //parse line
        ss.clear();
        ss << temp_string;
        ss >> cc_number;
        ss >> cardholder_name_first;
        ss >> cardholder_name_second;
        ss >> type_of_card;
        ss >> balance;
        
        //add first and last name together
        cardholder_name = cardholder_name_first + " " + cardholder_name_second;
        
        //check the card type and insert it into the correct vector
        if(type_of_card == "Gold") {
            GoldCard new_goldcard (cc_number,cardholder_name,balance);
            golds.push_back(new_goldcard);
        }
        else if (type_of_card == "Plat") {
            PlatCard new_platcard (cc_number,cardholder_name,balance);
            plats.push_back(new_platcard);
        }
        else if (type_of_card == "Corp") {
            CorpCard new_corpcard (cc_number,cardholder_name,balance);
            corps.push_back(new_corpcard);
        }
        else {
            cout << "Card of invalid type detected - card not stored" << endl;
        }
        
        
    } //<--end of file read: cc_data.txt
    
    //create variables to hold temporary data pulled from transaction file
    //temp_string holds the current line from the transaction file
    //index_of_card records the index number where the credit card object was found that corresponds to the transaction
    string date = "",
           transaction_num = "",
           vendor = "";
    temp_string = "";
    int index_of_card = 0;
    
    //read in from transactions file (transactions.txt)
    while (!transactions.eof()) {
        getline(transactions, temp_string);
        
        ss.clear();
        //change all semi-colons to spaces
        replace(temp_string.begin(), temp_string.end(), ':', ' ');
        
        ss << temp_string;
        ss >> cc_number;
        ss >> date;
        ss >> transaction_num;
        ss >> vendor;
        ss >> purchase_amt;
        
        //create a new transaction object, populate it and place it into a vector of transactions
        Transactions new_transaction (cc_number,date,transaction_num,vendor,purchase_amt);
        cc_transactions.push_back(new_transaction);
        
    } //<--end of file read: transactions.txt
          
        
    //transaction validation routine: loop for each transaction and find to see if the card exists as one of the creditcard objects
    for (int i=0;i<cc_transactions.size();i++) {
        Transactions tempTrans = cc_transactions.at(i);
        cc_number = tempTrans.getCCNumber();
        
        //search through creditcard objects for CC number
        //Check gold cards
        for (int i=0;i<golds.size();i++){
            GoldCard tempGoldCard = golds.at(i);
            if (tempGoldCard.getCCNumber() == cc_number) {
                //cout << endl << "found the card its a gold card, index: " << i;
                balance = tempGoldCard.getBalance();
                max_balance = tempGoldCard.getMaxBalance();
                type_of_card = "Gold";
                index_of_card = i;
            }
        }
        
        //check for "already found" could be added to speed up program when iterating through large vectors
        //Check platinum cards
        for (int i=0;i<plats.size();i++){
            PlatCard tempPlatCard = plats.at(i);
            if (tempPlatCard.getCCNumber() == cc_number) {
                //cout << endl << "found the card its a plat card, index: " << i;
                balance = tempPlatCard.getBalance();
                max_balance = tempPlatCard.getMaxBalance();
                type_of_card = "Plat";
                index_of_card = i;
            }
        }
        
        //check for "already found" could be added to speed up program when iterating through large vectors
        //Check corporate cards
        for (int i=0;i<corps.size();i++){
            CorpCard tempCorpCard = corps.at(i);
            if (tempCorpCard.getCCNumber() == cc_number) {
                //cout << endl << "found the card its a corp card, index: " << i;
                balance = tempCorpCard.getBalance();
                max_balance = tempCorpCard.getMaxBalance();
                type_of_card = "Corp";
                index_of_card = i;
            }
        }
        
        //test transaction, build output and pass approval to card to change balance, and calculate rebate amounts
        tempTrans.setCCValidation(balance, max_balance);

        if (tempTrans.getCCValidation() == 0) {
            approved << "Transaction ID#: " << tempTrans.getTransactionNum()
                     << " Date:" << tempTrans.getDate() << " $" 
                     << tempTrans.getPurchaseAmt() << endl;
            string pass_approved = approved.str();
    
            //if transaction allowed change balance on card and calculate new balance
            //calculate rebate amount
            //add the transaction to the internal transaction array/vector inside the creditcard class (not functional)
            //add output to the transaction record (basically take the transaction and push it into a string of all transactions on that account)
            //card math should probably be computed inside the card class
            if (type_of_card == "Gold") {
                GoldCard tempGoldCard = golds.at(index_of_card);
                tempGoldCard.setBalance(balance, tempTrans.getPurchaseAmt());
                tempGoldCard.setRebateTotal(tempTrans.getPurchaseAmt());
                tempGoldCard.addTransaction (tempTrans.getCCNumber(), tempTrans.getDate(), tempTrans.getTransactionNum(), tempTrans.getVendor(), tempTrans.getPurchaseAmt());
                tempGoldCard.addOutput (pass_approved);
                golds.at(index_of_card) = tempGoldCard;
            }
            else if (type_of_card == "Plat") {
                PlatCard tempPlatCard = plats.at(index_of_card);
                tempPlatCard.setBalance(balance, tempTrans.getPurchaseAmt());
                tempPlatCard.setRebateTotal(tempTrans.getPurchaseAmt());
                tempPlatCard.addTransaction (tempTrans.getCCNumber(), tempTrans.getDate(), tempTrans.getTransactionNum(), tempTrans.getVendor(), tempTrans.getPurchaseAmt());
                tempPlatCard.addOutput (pass_approved);
                plats.at(index_of_card) = tempPlatCard;
            }
            else if (type_of_card == "Corp") {
                CorpCard tempCorpCard = corps.at(index_of_card);
                tempCorpCard.setBalance(balance, tempTrans.getPurchaseAmt());
                tempCorpCard.setRebateTotal(tempTrans.getPurchaseAmt());
                tempCorpCard.addTransaction (tempTrans.getCCNumber(), tempTrans.getDate(), tempTrans.getTransactionNum(), tempTrans.getVendor(), tempTrans.getPurchaseAmt());
                tempCorpCard.addOutput (pass_approved);
                corps.at(index_of_card) = tempCorpCard;
            }
            
            //clear the approved stringstream
            approved.str("");
            
        }
        //otherwise if its not approved add it to the list of denied transactions to output
        //Reason 1 - failed luhn check
        else if (tempTrans.getCCValidation() == 1) {
            denied  << "Transaction ID#: " << tempTrans.getTransactionNum() 
                    << " -- DENIED: Failed Luhn Check" << endl;
        }//Readon 2 - failed/exceeded credit line
        else if (tempTrans.getCCValidation() == 2) {
            denied << "Transaction ID#: " << tempTrans.getTransactionNum()
                   << " -- DENIED: Exceeded Credit Line" << endl;
        }
        
    }
          
    //Output all object information:
    //Loop through all gold cards and output information on each object
    for (int i=0;i<golds.size();i++){
        GoldCard tempGoldCard = golds.at(i);
        cout << tempGoldCard.getCardholderName() << endl << "List of Approved Transactions: "<< endl;
        cout << tempGoldCard.getOutput();
        cout << endl << setprecision (2) << fixed << "Rebate Total: $" << tempGoldCard.getRebateTotal();
        cout << endl << "Total Expense: $" << tempGoldCard.getBalance() << endl;
    }
    //Loop through all platinum cards and output information on each object
    for (int i=0;i<plats.size();i++){
        PlatCard tempPlatCard = plats.at(i);
        cout << tempPlatCard.getCardholderName() << endl << "List of Approved Transactions: "<< endl;
        cout << tempPlatCard.getOutput();
        cout << endl << setprecision (2) << fixed << "Rebate Total: $" << tempPlatCard.getRebateTotal();
        cout << endl << "Total Expense: $" << tempPlatCard.getBalance() << endl;
    }
    //Loop through all corp cards and output information on each object
    for (int i=0;i<corps.size();i++){
        CorpCard tempCorpCard = corps.at(i);
        cout << tempCorpCard.getCardholderName() << endl << "List of Approved Transactions: " << endl;
        cout << tempCorpCard.getOutput();
        cout << endl << setprecision (2) << fixed << "Rebate Total: $" << tempCorpCard.getRebateTotal();
        cout << endl << "Total Expense: $" << tempCorpCard.getBalance() << endl;
    }
    
    //display denied cards
    cout << endl << denied.str();
    
    //close input/output file streams
    transactions.close();
    cc_data.close();
    
    //Program Output
    /*
    Bill Gates
List of Approved Transactions: 
Transaction ID#: 00001001 Date:01/01/2018 $320.2
Transaction ID#: 00001002 Date:01/01/2018 $100.49
Transaction ID#: 00001004 Date:01/03/2018 $75
Transaction ID#: 00001005 Date:01/05/2018 $30.2
Transaction ID#: 00001006 Date:01/08/2018 $145.25
Transaction ID#: 00001007 Date:01/09/2018 $103.75

Rebate Total: $15.50
Total Expense: $1174.89
Jerry Seinfeld
List of Approved Transactions: 
Transaction ID#: 00001009 Date:01/10/2018 $73.93

Rebate Total: $3.70
Total Expense: $1073.93

List of Denied Transactions: 
Transaction ID#: 00001003 -- DENIED: Failed Luhn Check


Transaction ID#: 00001009 -- DENIED: Exceeded Credit Line when you change expense to something high priced past the card limit
*/

    
    return 0;
}