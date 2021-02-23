#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void withdraw(double* balance, double amount) {
  if (*balance < amount) {
    cout << "You are broke. You don't have enough money. Go away" << endl;
  }
  else { *balance -= amount; }
}

void deposit(double* balance, double amount) { *balance += amount; }


int main() {

  double *balance;

  double harry_account_balance = 0;

  balance = &harry_account_balance;

  cout << "Harry's Balance at start is: " << harry_account_balance;
  cout << endl;
  double amount  = 1000.00; //setting the amount to be deposited

  deposit(balance, amount);

  cout << "Balance in harry account is: " << harry_account_balance;
  cout << endl;
  amount = 500; //setting amount to 500
  withdraw(balance, amount);

  cout << "Balance after withdrawing cash is: " << harry_account_balance;
  cout << endl;
  amount = 3000; //setting amount to 3000
  
  cout << "Withdrawing " << amount << " now" << endl;

  withdraw(balance, amount);

  return 0;
}
