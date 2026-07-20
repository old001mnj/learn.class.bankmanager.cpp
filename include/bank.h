#pragma once

#include "account.h"
#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>

class Bank {
  private:
    std::unordered_map<std::int64_t, std::unique_ptr<Account>> Accounts;
    std::string bankName;
    static std::int64_t nextId;

  public:
    void openAccount(int accountType_, const std::string &owner_,
                     double firstBalance_);
    void closeAccount(std::int64_t accountId_);
    std::unique_ptr<Account> &getAccount(std::int64_t accountId_);
    // getAccount 和 transfer 默认账户存在，需要在manager中确认是否存在所求kv对
    void transfer(std::int64_t fromId_, std::int64_t toId_, double amount_);
    void listAccounts();
};
