#include "transactions.h"

        //constructor
        Transactions::Transactions () {
            cc_number_ = "";
            date_ = "";
            transaction_num_ = "";
            vendor_ = "";
            purchase_amt_ = 0.0;
            decline_reason_ = 0;
        }

        
        //accessors
        //return credit card number
        const string Transactions::getCCNumber () {
            return cc_number_;
        }
        //return date of transaction
        const string Transactions::getDate () {
            return date_;
        }
        //return unique number identifier of the transaction
        const string Transactions::getTransactionNum() {
            return transaction_num_;
        }
        //return the name of the vendor used in the transaction
        const string Transactions::getVendor() {
            return vendor_;
        }
        //return the amount of money transacted
        const double Transactions::getPurchaseAmt() {
            return purchase_amt_;
        }
        //return the validation of the card
        const int Transactions::getCCValidation() {
            return decline_reason_;
        }

        //mutators
        //set the credit card number of the transaction
        void Transactions::setCCNumber (string cc_number) {
            cc_number_ = cc_number;
        }
        //set the date of the transaction
        void Transactions::setDate (string date) {
            date_ = date;
        }
        //set the unique identifier of the transaction
        void Transactions::setTransactionNum(string transaction_num) {
            transaction_num_ = transaction_num;
        }
        //set the name of the vendor used in the transaction
        void Transactions::setVendor(string vendor) {
            vendor_ = vendor;
        }
        //set the amount of money that the purchase was for
        void Transactions::setPurchaseAmt (double purchase_amt) {
            purchase_amt_ = purchase_amt;
        }
        
        //Checks the transaction's validity:
        /*
          1.) Luhn Algorithm
          2.) Current Balance vs Credit Limit
        */
        void Transactions::setCCValidation (double current_bal, double credit_limit) {
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
