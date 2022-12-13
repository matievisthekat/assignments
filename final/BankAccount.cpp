class BankAccount {
  public:
    float balance;
    int numDepositsThisMonth;
    int numWithdrawsThisMonth;
    float annualInterestRate;
    float monthlyServiceCharges;

    BankAccount(float balance, float annualInterestRate) {
      this->balance = balance;
      this->annualInterestRate = annualInterestRate;
    }

    virtual void deposit(float amt) {
      balance += amt;
      numDepositsThisMonth += 1;
    }

    virtual void withdraw(float amt) {
      balance -= amt;
      numWithdrawsThisMonth += 1;
    }

    virtual void calcInt() {
      float monthlyInterestRate = annualInterestRate / 12;
      float monthlyInterest = balance * monthlyInterestRate;
      balance += monthlyInterest;
    }

    virtual void monthlyProc() {
      balance -= monthlyServiceCharges;
      calcInt();
      numWithdrawsThisMonth = 0;
      numDepositsThisMonth = 0;
      monthlyServiceCharges = 0;
    }
};