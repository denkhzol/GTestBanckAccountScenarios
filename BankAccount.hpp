#pragma once
#include <memory>

class BankAccount{
    public:
        BankAccount();
        void deposit(double amount);
        void withdraw(double amount);
        double getBalance() const;
        void transfer(BankAccount &to, double unit);

        // Using smart (shared) pointer
        void transfer(std::shared_ptr<BankAccount> to, double unit);
    private:
        double balance;
};