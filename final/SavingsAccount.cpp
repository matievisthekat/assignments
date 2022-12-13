#include "BankAccount.cpp"

class SavingsAccount : public BankAccount {
  bool status = true;

  public:
    void withdraw(float amt) {
      if (status) {
        BankAccount::withdraw(amt);
      }
    }

    void deposit(float amt) {
      if (!status && (balance + amt) > 25) {
        status = true;
      }

      BankAccount::deposit(amt);
    }

    void monthlyProc() {
      if (numWithdrawsThisMonth > 4) {
        int addedFee = numWithdrawsThisMonth - 4;
        BankAccount::monthlyServiceCharges += addedFee;
      }

      BankAccount::monthlyProc();

      if (balance < 25) {
        status = false;
      }
    }
};