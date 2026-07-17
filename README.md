# 基于CPP的OOP特性的练习题

各类的详细要求(原题是基于python的，所以cpp写出来会有部分差异，由于部分原因也未使用cpp的异常处理

1. `Account`（基类）

```python
属性：
- account_id: str      # 唯一账号
- owner: str           # 户主
- balance: float       # 余额（protected，子类可访问）

方法：
- deposit(amount)      # 存款，正数校验
- withdraw(amount)     # 取款，余额+正数校验（抽象或基类实现）
- get_balance()        # 查余额
- __str__()            # 格式化输出
```

2. `SavingsAccount`（储蓄账户）
- 继承 `Account`
- 有 `interest_rate`（年利率）
- `apply_interest()`：按利率结算利息到余额
- 可能有 `withdraw_limit`（每月取款次数限制）

3. `CheckingAccount`（活期/支票账户）
- 继承 `Account`
- 有 `overdraft_limit`（透支额度，可透支到负数）
- `withdraw()` 重写：允许透支但不能超过额度
- 可能有 `transaction_fee`（每笔手续费）

4. `CreditCardAccount`（信用卡账户）
- 不继承 Account 或单独设计（信用卡逻辑不同）

```
属性：
- credit_limit: float      # 信用额度
- current_debt: float      # 当前欠款（消费金额）
- available_credit: float  # 可用额度

方法：
- charge(amount)           # 消费，不能超过可用额度
- make_payment(amount)     # 还款，从银行账户扣款或现金
- get_statement()          # 生成账单
- calculate_interest()     # 未还款部分计算利息
```

5. `Bank`（银行类）—— 核心调度

```
属性：
- accounts: dict[str, Account]   # 账号 -> 账户对象
- name: str

方法：
- open_account(type, owner, **kwargs) -> account_id   # 开户
- close_account(account_id)                           # 销户
- get_account(account_id) -> Account                  # 查账户
- transfer(from_id, to_id, amount)                    # 跨账户转账
- get_total_balance() -> float                        # 银行总存款
- list_accounts() -> list                             # 列出所有账户
```
