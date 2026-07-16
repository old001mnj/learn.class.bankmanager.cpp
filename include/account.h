#pragma once

#include <cstdint>
#include <cstdlib>
#include <string>

class Account {
  private:
    std::int64_t id;
    std::string owner;

  protected:
    double balance;

  public:
    Account(std::int64_t id_, const std::string &owner_, double balance_);
    virtual void deposit(double amount_);
    virtual void withdraw(double amount_);
    double getBalance() const;
    std::int64_t getId() const;
    const std::string &getOwner() const;
    virtual ~Account();
};
