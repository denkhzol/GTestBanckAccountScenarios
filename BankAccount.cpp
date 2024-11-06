#include "BankAccount.hpp"
#include <iostream>
#include <stdexcept>

BankAccount::BankAccount() : balance(0.0) {}

void BankAccount::deposit(double amount)
{
    balance += amount;

    std::cout << this << ": " << amount << " deposited by calling deposit()" << std::endl;
}

void BankAccount::withdraw(double amount)
{
    if(balance < amount)
    {
        throw std::runtime_error("Insufficient balance.");
    }

    balance -= amount;
    std::cout << this << ": " <<  amount << " deducted by calling withdraw()" << std::endl;
}

double BankAccount::getBalance() const{
    std::cout << this << ": " <<  "balance: " << balance << " by calling getBalance()" << std::endl;

    return balance;
}

void BankAccount::transfer(BankAccount &to, double amount)
{
    withdraw(amount);
    std::cout << this << ": " <<  "transfer(): " << amount << " withdrawn from " << this << std::endl;
    
    to.deposit(amount);
    std::cout << this << ": " <<  "transfer(): " << amount << " deposited to " << &to << std::endl;
}

void BankAccount::transfer(std::shared_ptr<BankAccount> to, double amount)
{
    withdraw(amount);
    std::cout << this << ": " <<  "transfer(): " << amount << " withdrawn from " << this << std::endl;
    
    to->deposit(amount);
    std::cout << this << ": " <<  "transfer(): " << amount << " deposited to " << &to << std::endl;
}