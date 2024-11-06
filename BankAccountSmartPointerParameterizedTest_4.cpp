#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>
#include <memory>
#include "BankAccount.hpp"

// Define a test fixture class for parameterized tests
class BankAccountParameterizedTestFixture : public testing::TestWithParam<std::tuple<int, int, int>>{
    protected:
        void SetUp() override;

        std::unique_ptr<BankAccount> account;
};

// Using smart (unique) pointer
void BankAccountParameterizedTestFixture::SetUp(){
    std::cout << "SetUp called" << std::endl;

    account = std::make_unique<BankAccount>();
}


// Use the test fixture in a parameterized test
TEST_P(BankAccountParameterizedTestFixture, MultipleInputs) {
    int deposit = std::get<0>(GetParam());
    int withdraw = std::get<1>(GetParam());
    int expected_balance = std::get<2>(GetParam());

    account->deposit(deposit);
    account->withdraw(withdraw);
    EXPECT_EQ(account->getBalance(), expected_balance);
}

// Define the values for the parameterized test
INSTANTIATE_TEST_SUITE_P(
    BankAccountTests,
    BankAccountParameterizedTestFixture,
    ::testing::Values(
        std::make_tuple(100.0, 50.0, 50.0),
        std::make_tuple(200.5, 100.0, 100.5),
        std::make_tuple(400.0, 500.0, 400.0), // withdrawal more than balance should not change balance
        std::make_tuple(300.0, 300.0, 0.0)
    )
);

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}

