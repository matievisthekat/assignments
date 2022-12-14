#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
  float save_start_bal = 0;
  float save_annual_int = 0;

  float check_start_bal = 0;
  float check_annual_int = 0;


  // Get starting details for Savings Account
  cout << "Enter the starting balance of your Savings Account: ";
  string save_start_bal_str;
  getline(cin, save_start_bal_str);
  save_start_bal = stof(save_start_bal_str);

  cout << "Enter the annual interest rate of your Savings Account: ";
  string save_annual_int_str;
  getline(cin, save_annual_int_str);
  save_annual_int = stof(save_annual_int_str);


  // Get starting details for Checking Account
  cout << "Enter the starting balance of your Checking Account: ";
  string check_start_bal_str;
  getline(cin, check_start_bal_str);
  check_start_bal = stof(check_start_bal_str);

  cout << "Enter the annual interest rate of your Checking Account: ";
  string check_annual_int_str;
  getline(cin, check_annual_int_str);
  check_annual_int = stof(check_annual_int_str);


  // Instansiate our savings and checking accounts classes 
  SavingsAccount save = SavingsAccount(save_start_bal, save_annual_int);
  CheckingAccount check = CheckingAccount(check_start_bal, check_annual_int);


  // Main menu feedback loop
  while(true) {
    cout << "Main Menu" << endl
         << "- [0] Exit" << endl
         << "- [1] Deposit into Savings Account" << endl
         << "- [2] Withdraw from Savings Account" << endl
         << "- [3] Deposit into Checking Account" << endl
         << "- [4] Withdraw from Checking Account" << endl
         << "- [5] View statistics for Savings Account" << endl
         << "- [6] View statistics for Checking Account" << endl
         << "Please select an action using the number in []: " << endl;
    string sel;
    getline(cin, sel);

    if (sel == "0") {
      break;
    } else if (sel == "1") {
      cout << "Please enter the amount you wish to deposit: ";
      string amt_str;
      getline(cin, amt_str);
      float amt = stof(amt_str);

      save.deposit(amt);
      cout << "You have deposited $" << amt << endl
           << "- [0] Back" << endl
           << "Enter selection: ";
      
      string back;
      getline(cin, back);
      continue;
    } else if (sel == "2") {
      cout << "Please enter the amount you with to withdraw: ";
      string amt_str;
      getline(cin, amt_str);
      float amt = stof(amt_str);

      save.withdraw(amt);
      cout << "You have withdrawn $" << amt << endl
           << "- [0] Back" << endl
           << "Enter selection: ";

      string back;
      getline(cin, back);
      continue;
    } else if (sel == "3") {
      cout << "Please enter the amount you wish to deposit: ";
      string amt_str;
      getline(cin, amt_str);
      float amt = stof(amt_str);

      check.deposit(amt);
      cout << "You have deposited $" << amt << endl
           << "- [0] Back" << endl
           << "Enter selection: ";
      
      string back;
      getline(cin, back);
      continue;
    } else if (sel == "4") {
      cout << "Please enter the amount you with to withdraw: ";
      string amt_str;
      getline(cin, amt_str);
      float amt = stof(amt_str);

      check.withdraw(amt);
      cout << "You have withdrawn $" << amt << endl
           << "- [0] Back" << endl
           << "Enter selection: ";

      string back;
      getline(cin, back);
      continue;
    } else if (sel == "5") {
      string status_str = save.status ? "ACTIVE" : "INACTIVE";
      cout << "Savings Account Statistics for this Month" << endl
           << "Status: " << status_str << endl
           << "Amount of Deposits made: " << save.numDepositsThisMonth << endl
           << "Amount of Withdrawals made: " << save.numWithdrawsThisMonth << endl
           << "Beginning Balance: $" << save.balance << endl;

      float begin_bal = save.balance;
      save.monthlyProc();
      float end_bal = save.balance;

      cout << "Service Fees: $" << begin_bal - end_bal << endl
           << "Ending Balance: $" << save.balance << endl << endl
           << "- [0] Back" << endl
           << "Enter selection: ";
    
      string back;
      getline(cin, back);
      continue;
    } else if (sel == "6") {
      cout << "Checking Account Statistics for this Month" << endl
           << "Amount of Deposits made: " << check.numDepositsThisMonth << endl
           << "Amount of Withdrawals made: " << check.numWithdrawsThisMonth << endl
           << "Beginning Balance: $" << check.balance << endl;

      float begin_bal = check.balance;
      save.monthlyProc();
      float end_bal = check.balance;

      cout << "Service Fees: $" << begin_bal - end_bal << endl
           << "Ending Balance: $" << check.balance << endl << endl
           << "- [0] Back" << endl
           << "Enter selection: ";
    
      string back;
      getline(cin, back);
      continue;
    }
  }

  return 0;
}
