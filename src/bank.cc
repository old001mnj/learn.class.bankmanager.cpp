#include "bank.h"
#include "account.h"
#include "checking_account.h"
#include "credit_card_account.h"
#include "savings_account.h"
#include <cstdint>
#include <iostream>
#include <memory>

void Bank::openAccount(int accountType_, const std::string &owner_,
                       double firstBalance_) {
    std::int64_t tmpId = ++this->nextId;
ACCTYPE:
    switch (accountType_) {
    case 1:
        // 储蓄账户
        this->Accounts.emplace(
            tmpId, std::unique_ptr<Account>(std::make_unique<SavingsAccount>(
                       tmpId, owner_, firstBalance_)));
        break;
    case 2:
        this->Accounts.emplace(
            tmpId, std::unique_ptr<Account>(std::make_unique<CreditCardAccount>(
                       tmpId, owner_, firstBalance_)));
        break;
    case 3:
        // 活期账户
        this->Accounts.emplace(
            tmpId, std::unique_ptr<Account>(std::make_unique<CheckingAccount>(
                       tmpId, owner_, firstBalance_)));
        break;

    default:
        std::cout << "请在1, 2, 3中挑选" << std::endl;
        goto ACCTYPE;
        break;
    }
}

std::int64_t Bank::nextId = 1000000;

void Bank::closeAccount(std::int64_t accountId_) {
    if (!(this->Accounts.count(accountId_))) {
        std::cout << "账户不存在" << std::endl;
        return;
    }
    this->Accounts.erase(accountId_);
    std::cout << "账户已删除" << std::endl;
}

std::unique_ptr<Account> &Bank::getAccount(std::int64_t accountId_) {
    return this->Accounts[accountId_];
}

void Bank::transfer(std::int64_t fromId_, std::int64_t toId_, double amount_) {
    this->Accounts[fromId_]->deposit(amount_);
    this->Accounts[toId_]->withdraw(amount_);
}

void Bank::listAccounts() {
    for (auto &[k, v] : Accounts) {
        std::cout << "账户ID: " << k << "，所有人：" << v->getOwner()
                  << std::endl;
    }
}
