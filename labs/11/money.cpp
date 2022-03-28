#include "money.h"

// This function definition provided as an example
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

// CLASS FUNCTION DEFINITIONS GO HERE
  const Money operator -(const Money& amount1, const Money& amount2){
  return amount1+(-amount2);
  }
  bool operator ==(const Money &amount1, const Money &amount2){
  return amount1.dollars()==amount2.dollars()&&amount1.cents()==amount2.cents();
  }
  const Money operator -(const Money &amount){
  Money result;
  result.set_cents(-amount.cents());
  result.set_dollars(-amount.dollars());
  return result;
  }
  ostream& operator <<(ostream &out, const Money &amount){
    if(amount.dollars()<0||amount.cents()<0){
    out << "$-" << abs(amount.dollars()) << ".";
    out << setfill ('0') << setw (2);
    out << abs(amount.cents()); 
    }else{
    out << "$" << amount.dollars() << ".";
    out << setfill ('0') << setw (2);
    out << abs(amount.cents()); 
    }
    return out;
  }