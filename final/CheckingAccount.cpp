#include "BankAccount.cpp"

class CheckingAccount : public BankAccount {
  public:
    void withdraw(float amt) {
      if (balance - amt < 0) {
        balance -= 15;
      } else {
        BankAccount::withdraw(amt);
      }
    }

    void monthlyProc() {
      float fee = 5 + (numWithdrawsThisMonth * 0.1);
      BankAccount::monthlyServiceCharges += fee;
    }
};