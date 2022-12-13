#include "BankAccount.h"

BankAccount::BankAccount(float balance, float annualInterestRate) {
  this->balance = balance;
  this->annualInterestRate = annualInterestRate;
}

void BankAccount::deposit(float amt) {
  balance += amt;
  numDepositsThisMonth += 1;
}

void BankAccount::withdraw(float amt) {
  balance -= amt;
  numWithdrawsThisMonth += 1;
}

void BankAccount::calcInt() {
  float monthlyInterestRate = annualInterestRate / 12;
  float monthlyInterest = balance * monthlyInterestRate;
  balance += monthlyInterest;
}

void BankAccount::monthlyProc() {
  balance -= monthlyServiceCharges;
  calcInt();
  numWithdrawsThisMonth = 0;
  numDepositsThisMonth = 0;
  monthlyServiceCharges = 0;
}
