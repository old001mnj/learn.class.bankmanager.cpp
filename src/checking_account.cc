#include "checking_account.h"
#include <iostream>

double CheckingAccount::OverdraftLimit_ = 1200.00;

void CheckingAccount::withdraw(double amount_) {
    if (amount_ <= 0 || amount_ >= (this->balance + this->OverdraftLimit_)) {
        if (amount_ <= 0) {
            std::cout << "取钱金额不能为0" << std::endl;
        } else {
            std::cout << "所取金额已超过透支极限" << std::endl;
        }
        return;
    }

    if (amount_ <= this->balance) {
        this->balance -= amount_;
        std::cout << "取款成功，当前余额：" << this->balance << std::endl;
    } else if (amount_ >= this->balance &&
               amount_ <= (this->balance + this->OverdraftLimit_)) {
        this->balance = 0;
        this->OverdraftLimit_ -= (amount_ - this->balance);
        std::cout << "余额不足，已自动扣除可透支额度，剩余可透支额度："
                  << this->OverdraftLimit_ << std::endl;
    } else {
        std::cout << "未知错误" << std::endl;
    }
    return;
}
