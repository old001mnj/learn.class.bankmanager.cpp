#include "account.h"
#include <iostream>

Account::Account(std::int64_t id_, const std::string &owner_, double balance_)
    : id(id_), balance(balance_), owner(owner_) {}

void Account::deposit(double amount_) {
    bool isMinus = (amount_ <= 0);
    if (isMinus) {
        std::cout << "存款金额不能为非正数" << std::endl;
        return;
    }
    this->balance += amount_;
    std::cout << "存款成功，当前余额：" << this->balance << std::endl;
}

void Account::withdraw(double amount_) {
    if (amount_ <= 0 || amount_ > this->balance) {
        if (amount_ <= 0)
            std::cout << "取款金额不能为非正数" << std::endl;
        else if (amount_ > this->balance)
            std::cout << "余额不足" << std::endl;

        return;
    }
    this->balance -= amount_;
    std::cout << "取款成功，当前余额：" << this->balance << std::endl;
}

double Account::getBalance() const {
    // std::cout << "当前余额：" << this->balance << std::endl;
    return this->balance;
}

std::int64_t Account::getId() const { return this->id; }

const std::string &Account::getOwner() const { return this->owner; }
