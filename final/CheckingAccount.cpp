#include "CheckingAccount.h"

void CheckingAccount::withdraw(float amt) {
  // If the withdrawal amount will make the balance negative, charge a fee of $15 and deny the withdrawal
  if (balance - amt < 0) {
    balance -= 15;
  } else {
    BankAccount::withdraw(amt);
  }
}

void CheckingAccount::monthlyProc() {
  // Charge a base fee of $5 plus $0.10 for each withdrawal in the month
  float fee = 5 + (numWithdrawsThisMonth * 0.1);
  BankAccount::monthlyServiceCharges += fee;
}
