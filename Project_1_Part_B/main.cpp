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
#include "transactions.h"
#include "creditcard.h"
#include "goldcard.h"
#include "platcard.h"
#include "corpcard.h"

using namespace std;

//Create three subclasses of each card type 


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
    //The vectors will hold the specific card objects
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
        //but not before assigning it all the values extracted from the file
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
        //testing the balance through the transaction class should be changed to a function of the card itself
        //whereas the luhn validation could remain part of the transaction class (balance data is logically connected
        //to the card object and testing card number accuracy is logically part of the transaction object)
        //This is the last error in the program essentially, if this check is removed, and 
        tempTrans.setCCValidation(balance, max_balance);

        if (tempTrans.getCCValidation() == 0) {
            
            //create a string of the successful transaction along with the important data then pass it
            //to the object's addOutput function
            approved << "Transaction ID#: " << tempTrans.getTransactionNum()
                     << " Date:" << tempTrans.getDate() << " $" 
                     << tempTrans.getPurchaseAmt() << endl;
            string pass_approved = approved.str();
    
            //if transaction allowed change balance on card and calculate new balance
            //calculate rebate amount
            //add the transaction to the internal transaction array/vector inside the creditcard class (not functional)
            //add output to the transaction record (basically take the transaction and push it into a string of all transactions on that account)
            //card math should probably be computed inside the card class
            //this is the last error in the program
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
        }//Reason 2 - failed/exceeded credit line
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