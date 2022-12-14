#ifndef BankAccount_H

#define BankAccount_H

class BankAccount {
  public:
    float balance;
    int numDepositsThisMonth;
    int numWithdrawsThisMonth;
    float annualInterestRate;
    float monthlyServiceCharges;

    BankAccount(float balance, float annualInterestRate);

    virtual void deposit(float amt);
    virtual void withdraw(float amt);
    virtual void calcInt();
    virtual void monthlyProc();
};

#endif
