#include "SavingsAccount.h"

void SavingsAccount::withdraw(float amt) {
  // If the account is active (i.e. if "status" is true)
  if (status) {
    BankAccount::withdraw(amt);
  }
}

void SavingsAccount::deposit(float amt) {
  // If the account is inactive and the deposit amount will make the account balance go above $25, then set the account as active
  if (!status && (balance + amt) > 25) {
    status = true;
  }

  BankAccount::deposit(amt);
}

void SavingsAccount::monthlyProc() {
  if (numWithdrawsThisMonth > 4) {
    // Charge $1 for each withdrawal (excluding the first 4 withdrawals)
    int addedFee = numWithdrawsThisMonth - 4;
    BankAccount::monthlyServiceCharges += addedFee;
  }

  BankAccount::monthlyProc();

  // If balance falls below $25, set the account status to false (i.e. inactive)
  if (balance < 25) {
    status = false;
  }
}
