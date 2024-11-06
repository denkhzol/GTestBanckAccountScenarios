#include "BankAccount.hpp"
#include <iostream>

int main() {
    BankAccount account1;
    BankAccount account2;

    account1.deposit(1000.0);
    account1.withdraw(200.0);
    account1.transfer(account2, 300.0);

    std::cout << "Account 1 balance: " << account1.getBalance() << std::endl;
    std::cout << "Account 2 balance: " << account2.getBalance() << std::endl;

    return 0;
}
