#pragma once

#include "account.h"
#include <cstdint>
class CreditCardAccount : public Account {
  private:
    double creditLimit;
    double currentDebt;
    double availableCredit;

  public:
    CreditCardAccount(std::int64_t id_, const std::string &owner_,
                      double balance_);
    void charge(double amount_);
    void makePayment(double amount_);
    void getStatement();
    void calculateInterest();
    void setCreditLimit(double creditLimit_);
};
