#pragma once

#include "account.h"
#include <cstdint>
#include <string>

class CheckingAccount : public Account {
  private:
    static double OverdraftLimit_;

  public:
    CheckingAccount(std::int64_t id_, const std::string &owner_,
                    double balance_);
    virtual void withdraw(double amount_) override;
};
