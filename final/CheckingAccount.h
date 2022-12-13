#include "BankAccount.h"

class CheckingAccount : public BankAccount {
  public:
    CheckingAccount(float balance, float annualInterestRate) : BankAccount(balance, annualInterestRate) {}

    void withdraw(float amt);
    void monthlyProc();
};
