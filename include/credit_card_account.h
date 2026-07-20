#pragma once

class CreditCardAccount {
  private:
    double creditLimit;
    double currentDebt;
    double availableCredit;

  public:
    void charge(double amount_);
    void makePayment(double amount_);
    void getStatement();
    void calculateInterest();
    void setCreditLimit(double creditLimit_);
};
