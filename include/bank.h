#pragma once

#include "account.h"
#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>

class Bank {
  private:
    std::unordered_map<std::int64_t, Account> Accounts;
    std::string bankName;

  public:
    void openAccount(int accountType_, const std::string &owner_,
                     double firstBalance_);
    void closeAccount(std::int64_t accountId_);
    std::shared_ptr<Account> getAccount(std::int64_t accountId_);
    void transfer(std::int64_t fromId_, std::int64_t toId_, double amount_);
    double getAllBalance();
    void listAccounts();
};
