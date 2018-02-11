/*
 * Name        : money.h
 * Author      : FILL IN
 * Description : Class Header File
 */

// ADD HEADER GUARD HERE

#ifndef money_h
#define money_h

#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;
using std::string;
using std::ostream;
using std::setfill;
using std::setw;

/*
 * Class Money.
 * A class that handles amounts of money in U.S. Currency.
 */
class Money {
 public:
  /*
   * Constructor #1.
   * Sets dollars and cents to the supplied values. Defaults to 0
   * @param int dollars - The value to set dollars_ to
   * @param int cents - The value to set cents_ to
   */
  Money(int dollars = 0, int cents = 0);

  /*
   * Accessor for dollars_
   * @return int - The dollars_ value
   */
  int dollars() const;

  /*
   * Accessor for cents_
   * @return int - The cents_ value
   */
  int cents() const;

  /*
   * Mutator for dollars_
   * @param int dollars - The value to set dollars_ to
   */
  void set_dollars(int dollars);

  /*
   * Mutator for cents_
   * @param int cents - The value to set cents_ to
   */
  void set_cents(int cents);

  friend const Money operator +(const Money& amount1, const Money& amount2);

  friend const Money operator -(const Money& amount1, const Money& amount2);

  friend bool operator ==(const Money &amount1, const Money &amount2);

  friend const Money operator -(const Money &amount);

  friend ostream& operator <<(ostream &out, const Money &amount);

 private:
  int dollars_;
  int cents_;
};

#endif