#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>
#include "BankAccount.hpp"

// Define a test fixture class
class BankAccountTestFixture : public testing::Test{
    protected:
        BankAccountTestFixture();
        virtual ~BankAccountTestFixture();
        void SetUp() override;
        void TearDown() override;
        static void SetUpTestCase();
        static void TearDownTestCase();

        BankAccount *account;
};

BankAccountTestFixture::BankAccountTestFixture(){
    std::cout << "Constructor called" << std::endl;
}

BankAccountTestFixture::~BankAccountTestFixture(){
    std::cout << "Destructor called" << std::endl;
}

// Using traditional pointer
void BankAccountTestFixture::SetUp(){
    std::cout << "SetUp called" << std::endl;

    account = new BankAccount();
}

void BankAccountTestFixture::TearDown(){
    std::cout << "TearDown called" << std::endl;
    delete account;
}

void BankAccountTestFixture::SetUpTestCase(){
    std::cout << "SetUpTestCase called" << std::endl;
}

void BankAccountTestFixture::TearDownTestCase(){
    std::cout << "TearDownTestCase called" << std::endl;
}

TEST(WithoutFixtureBankAccountTest, TestEmptyAccout){
    BankAccount account;

    ASSERT_EQ(0.0, account.getBalance());
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

TEST_F(BankAccountTestFixture, TestWithdrawInsufficientBalance){
    ASSERT_THROW(account->withdraw(200), std::runtime_error);
}

TEST_F(BankAccountTestFixture, TestTransferFine){
    BankAccount to;

    account->deposit(50.5);
    account->transfer(to, 30.0);

    ASSERT_EQ(20.5, account->getBalance());

    ASSERT_EQ(30.0, to.getBalance());
}

TEST_F(BankAccountTestFixture, TestTransferInSufficientBalance){
    BankAccount to;

    ASSERT_THROW(account->transfer(to, 200), std::runtime_error);
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}