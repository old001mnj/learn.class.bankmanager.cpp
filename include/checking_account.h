#pragma once

#include "account.h"

class CheckingAccount : public Account {
  private:
    static double OverdraftLimit_;

  public:
    virtual void withdraw(double amount_) override;
};
