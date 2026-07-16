#include "savings_account.h"
#include "account.h"
#include <iostream>

const double SavingsAccount::insterstRate_ = 0.02;

SavingsAccount::SavingsAccount(std::int64_t id_, const std::string &owner_,
                               double balance_)
    : Account(id_, owner_, balance_) {}

/*
void SavingsAccount::applyInsterrst(double year) {
    long long tmp_inst = (long long)this->insterstRate_ * 100;
    this->balance += (double)((year * tmp_inst) / 100.00);
    std::cout << "利息收入后余额为：" << this->balance;
}
*/

void SavingsAccount::applyInsterrst(double year) {
    // 假设 insterstRate_ 是小数（0.025 表示 2.5%）
    double interest = this->balance * this->insterstRate_ * year;
    // 或者四舍五入到分：
    interest = round(interest * 100) / 100;
    this->balance += interest;
    std::cout << "利息收入后为：" << this->balance << std::endl;
}
