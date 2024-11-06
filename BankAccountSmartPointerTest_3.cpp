#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>
#include <memory>
#include "BankAccount.hpp"

// Define a test fixture class
class BankAccountTestFixture : public testing::Test{
    protected:
        void SetUp() override;

        std::unique_ptr<BankAccount> account;
};

// Using smart (unique) pointer
void BankAccountTestFixture::SetUp(){
    std::cout << "SetUp called" << std::endl;

    account = std::make_unique<BankAccount>();
}


// Use the test fixture in a test
TEST_F(BankAccountTestFixture, DepositTest){
    account->deposit(100.5);

    EXPECT_EQ(100.5, account->getBalance());
}

TEST_F(BankAccountTestFixture, WithdrawTest){
    account->deposit(50);
    account->withdraw(20);

    EXPECT_EQ(30, account->getBalance());
}

TEST_F(BankAccountTestFixture, TestTransferFine){
    
    std::shared_ptr<BankAccount> to = std::make_shared<BankAccount>();

    account->deposit(50.5);
    account->transfer(to, 30.0);

    ASSERT_EQ(20.5, account->getBalance());

    ASSERT_EQ(30.0, to->getBalance());
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}