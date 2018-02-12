#include "money.h"

// The Constructor, Accessors and Mutators have been defined for you
Money::Money(int dollars, int cents) : dollars_(dollars), cents_(cents) {
}

int Money::dollars() const {
    return dollars_;
}

int Money::cents() const {
    return cents_;
}

void Money::set_dollars(int dollars) {
  dollars_ = dollars;
}

void Money::set_cents(int cents) {
  cents_ = cents;
}
  
// This function definition provided as an example and is FULLY COMPLETE
const Money operator +(const Money& amount1, const Money& amount2) {
  // Get all the cents of object 1
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  // Get all the cents of object 2
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  // Add all the cents together
  int sum_all_cents = all_cents1 + all_cents2;
  // Handle the fact that money can be negative
  int abs_all_cents = abs(sum_all_cents);
  int final_dollars = abs_all_cents / 100;
  int final_cents = abs_all_cents % 100;
  // If the result of the operation was negative, negate final dollars and cents
  if (sum_all_cents < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }
  return Money(final_dollars, final_cents);
}

  /*
   * Overload of binary - operator. This is a friend function.
   * @param Money amount1 - The object to subtract from
   * @param Money amount2 - The object to be subtracted
   * @return Money - The result of the subtraction
   */
const Money operator -(const Money& amount1, const Money& amount2){
  // Get all the cents of object 1
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  // Get all the cents of object 2
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  // Add all the cents together
  int sub_all_cents = all_cents1 - all_cents2;
  // Handle the fact that money can be negative
  int abs_all_cents = abs(sub_all_cents);
  int final_dollars = abs_all_cents / 100;
  int final_cents = abs_all_cents % 100;
  // If the result of the operation was negative, negate final dollars and cents
  if (sub_all_cents < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }
  return Money(final_dollars, final_cents); 
}

  /*
   * Overload of == operator. This is a friend function.
   * @param Money amount1 - The first object to compare
   * @param Money amount2 - The second object to compare
   * @return bool - True if the objects have the same values, otherwise false
   */
   bool operator ==(const Money &amount1, const Money &amount2) {
        bool value = false;
        // Get all the cents of object 1
        int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
        // Get all the cents of object 2
        int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
        
        if (all_cents1 == all_cents2) {
            value = true;
        }
        
        return value;
   }

  /*
   * Overload of unary - operator. This is a friend function.
   * @param Money amount - The object to negate
   * @return Money - The result of the negation of the two member variables
   */
   const Money operator -(const Money &amount) {
     int neg_cents =  -amount.cents_;
     int neg_dollars = -amount.dollars_;
     //amount.cents_ = -amount.cents_;
     //amount.dollars_ = -amount.dollars_;
     return Money(neg_dollars, neg_cents);
   }

  /*
   * Overload of << operator.
   * Outputs the money values to the output stream.
   * Should be in the form $x.xx
   * @uses setw()
   * @uses setfill()
   * @param ostream &out - The ostream object to output to
   * @param Money amount - The Money object to output from.
   * @return ostream& - The ostream object to allow for chaining of <<
   */
   ostream& operator <<(ostream &out, const Money &amount) {
        int all_cents = amount.cents_ + amount.dollars_ * 100;
        
        if (all_cents >= 0) {
            //positive
            if (amount.cents_ > 9) {
                out << "$" << amount.dollars_ << "." << amount.cents_; 
            }
            else {
                out << "$" << amount.dollars_ << ".0" << amount.cents_;
            }
        }
        else {
            //negative
            int final_cents = abs(amount.cents_);
            
            if ((final_cents > 9) && (amount.dollars_ < 0)) {
                out << "$" << amount.dollars_ << "." << final_cents; 
            }
            else if ((final_cents > 9) && (amount.dollars_ == 0)) {
                out << "$-0." << final_cents;
            }
            else if ((final_cents<9) && (amount.dollars_ < 0)) {
                out << "$" << amount.dollars_ << ".0" << final_cents;
            }
            else if ((final_cents<9) && (amount.dollars_ == 0)) {
                out << "$-0.0"  << final_cents;
            }
        }
        
        return out;
   }


// REST OF CLASS FUNCTION DEFINITIONS GO HERE
