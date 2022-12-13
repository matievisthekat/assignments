#include "CheckingAccount.h"

void CheckingAccount::withdraw(float amt) {
  if (balance - amt < 0) {
    balance -= 15;
  } else {
    BankAccount::withdraw(amt);
  }
}

void CheckingAccount::monthlyProc() {
  float fee = 5 + (numWithdrawsThisMonth * 0.1);
  BankAccount::monthlyServiceCharges += fee;
}
