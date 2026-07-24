#include "manager.h"
#include "bank.h"
#include <cstdint>
#include <iostream>
#include <memory>
#include <string>

void MENU() {
    std::unique_ptr<Bank> bank = std::make_unique<Bank>();
    int business{10086};
    while (business != 0) {
        business = 0;
        std::cout << "请选择你要办理的业务：" << std::endl
                  << "0.退出" << std::endl
                  << "1.开户" << std::endl
                  << "2.注销账户" << std::endl
                  << "3.查账户" << std::endl
                  << "4.转账" << std::endl
                  << "5.列出全部账户" << std::endl;
        std::cin >> business;
        switch (business) {
        case 1: {
            std::cout << "账户类型：" << std::endl
                      << "1.储蓄账户\n"
                      << "2.信用卡账户\n"
                      << "3.活期账户\n"
                      << "选择账户类型：";
            int accountType_{0};
            std::cin >> accountType_;
            std::cout << "输入账户所有人：";
            std::string owner_;
            std::cin >> owner_;
            // std::cin >> owner_;
            std::cout << "输入激活账户存的钱数：";
            double firstBalance_;
            std::cin >> firstBalance_;
            bank->openAccount(accountType_, owner_, firstBalance_);
            break;
        }
        case 2: {
            std::int64_t AccId;
            std::cout << "输入账户ID: ";
            std::cin >> AccId;
            bank->closeAccount(AccId);
            break;
        }
        case 3: {
            std::cout << "输入账户ID: ";
            std::int64_t AccId;
            std::cin >> AccId;
            const auto &result = bank->getAccount(AccId);
            std::cout << "账户ID: " << result->getId() << ' '
                      << "户主: " << result->getOwner() << ' '
                      << "账户剩余金额: " << result->getBalance() << std::endl;
            break;
        }
        case 4: {
            std::int64_t fromId, toId;
            double amount_;
            std::cout << "输入转账账户ID: ";
            std::cin >> fromId;
            std::cout << "输入转账目标账户ID: ";
            std::cin >> toId;
            std::cout << "输入转账金额: ";
            std::cin >> amount_;
            bank->transfer(fromId, toId, amount_);
            break;
        }
        case 5: {
            bank->listAccounts();
            break;
        }
        case 0: {
            business = 0;
            break;
        }
        default: {
            business = 10086;
            std::cout << "暂无此业务" << std::endl;
            break;
        }
        }
    }
}
