#include "account.h"
#include "savings_account.h"

auto main() -> int {
    Account *djl = new Account{1, "djl", 34.5};
    djl->getBalance();
    djl->deposit(666.6);
    djl->withdraw(789.9);
    djl->getBalance();
    delete djl;
    SavingsAccount *sdjl = new SavingsAccount{3, "sdjl", 56.7};
    sdjl->deposit(789.98);
    sdjl->applyInsterrst(6.7);
    sdjl->getBalance();
    sdjl->withdraw(65.7);
    sdjl->getBalance();
    delete sdjl;
    return 0;
}
