#include <iostream>
#include <iomanip>
#include "bankAccount.h"

using namespace std;

// Default Constructor
bankAccount::bankAccount()
{
  firstName = "";
  lastName = "";
  account = 0;
  pin = 0;
  balance = 0;
}
// Constructor
bankAccount::bankAccount(string _firstName, string _lastName, int _account,  short _pin, float _bal)
{
  firstName = _firstName;
  lastName = _lastName;
  account = _account;
  pin = _pin;
  balance = _bal;
} 

// Display Account
void bankAccount::display() const
{ 
  cout << right;
  
  cout << setw(10) << firstName << setw(10) << lastName;
  cout << setw(10) << account  << setw(10) <<  pin  << setw(10) << balance << endl;

}