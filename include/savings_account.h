#include "account.h"
#include <cstdint>
#include <string>

class SavingsAccount : public Account {
  private:
    static const double insterstRate_;

  public:
    SavingsAccount(std::int64_t id_, const std::string &owner_,
                   double balance_);
    void applyInsterrst(double year);
};
