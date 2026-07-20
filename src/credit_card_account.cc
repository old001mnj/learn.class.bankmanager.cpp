#include "credit_card_account.h"
#include "account.h"
#include <cstdint>
#include <iostream>
#include <string>

CreditCardAccount::CreditCardAccount(std::int64_t id_,
                                     const std::string &owner_, double balance_)
    : Account(id_, owner_, balance_), availableCredit(balance_),
      creditLimit(balance_), currentDebt(0.00) {}

void CreditCardAccount::charge(double amount_) {
    if (amount_ <= 0) {
        std::cout << "取款数不能为负数或零" << std::endl;
        return;
    } else if (amount_ > this->availableCredit) {
        std::cout << "当前可用额度不足" << std::endl;
        return;
    }
    this->availableCredit -= amount_;
    this->currentDebt += (this->creditLimit - this->availableCredit);
    std::cout << "取款成功" << std::endl;
}

void CreditCardAccount::makePayment(double amount_) {
    if (amount_ <= 0) {
        std::cout << "还款金额不能为零或负数" << std::endl;
        return;
    } else if (amount_ > this->currentDebt) {
        std::cout << "还款金额大于需还款金额，溢缴金自动转为可用余额"
                  << std::endl;
    }
    if (amount_ <= this->currentDebt) {
        this->currentDebt -= amount_;
    }
    this->availableCredit += amount_;
    std::cout << "还款成功" << std::endl;
}

void CreditCardAccount::calculateInterest() {
    this->currentDebt *= 0.05;
    /* 自动按一个月加利息，不足一月照算 */
}

void CreditCardAccount::getStatement() {
    std::cout << "当前信用卡信用额度为：" << this->creditLimit << "可用额度为："
              << this->availableCredit << "（包括缴纳的缴溢金）"
              << "当前欠款为：" << this->currentDebt << std::endl;
}

void CreditCardAccount::setCreditLimit(double creditLimit) {
    this->creditLimit = creditLimit;
}
