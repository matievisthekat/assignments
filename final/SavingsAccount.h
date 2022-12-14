#include "BankAccount.h"

class SavingsAccount : public BankAccount {
  public:
    bool status = true;
    
    SavingsAccount(float balance, float annualInterestRate) : BankAccount(balance, annualInterestRate) {}

    void withdraw(float amt);
    void deposit(float amt);
    void monthlyProc();
};
