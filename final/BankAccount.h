class BankAccount {
  public:
    float balance;
    int numDepositsThisMonth;
    int numWithdrawsThisMonth;
    float annualInterestRate;
    float monthlyServiceCharges;

    virtual void deposit(float amt);
    virtual void withdraw(float amt);
    virtual void calcInt();
    virtual void monthlyProc();
};