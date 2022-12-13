#include "BankAccount.h"

class SavingsAccount : public BankAccount {
  bool status = true;

  public:
    void withdraw(float amt);
    void deposit(float amt);
    void monthlyProc();
};
