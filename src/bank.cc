#include "bank.h"
#include <iostream>

void Bank::openAccount(int accountType_, const std::string &owner_,
                       double firstBalance_) {
    switch (accountType_) {
    case 1:
        // 储蓄账户
        break;
    case 2:
        // 信用卡账户
        break;
    case 3:
        // 活期账户
        break;

    default:
        std::cout << "请在1, 2, 3中挑选" << std::endl;
        break;
    }
}

void Bank::closeAccount(std::int64_t accountId_) {
    if (!(this->Accounts.count(accountId_))) {
        std::cout << "账户不存在" << std::endl;
        return;
    }
    this->Accounts.erase(accountId_);
    std::cout << "账户已删除" << std::endl;
}
