#include "BankAccount.h"

class CheckingAccount : public BankAccount {
  public:
    void withdraw(float amt);
    void monthlyProc();
};
