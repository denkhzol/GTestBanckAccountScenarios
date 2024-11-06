# GTestBankAccountScenarios

This repository was created as part of my journey to learn Google Test (GTest). It includes multiple test files that demonstrate various testing techniques and scenarios. These include managing BankAccount instances using traditional raw pointers, utilizing modern C++ smart pointers (std::unique_ptr and std::shared_ptr) for automatic memory management, and running parameterized tests to ensure comprehensive coverage with different sets of input parameters.

## Project Structure

- **BankAccount.hpp**: Header file defining the `BankAccount` class.
- **BankAccount.cpp**: Implementation of the `BankAccount` class methods.
- **BankAccountDemo_1.cpp**: A simple demonstration program using the `BankAccount` class.
- **BankAccountPointerTest_2.cpp**: Unit tests using traditional pointers.
- **BankAccountSmartPointerTest_3.cpp**: Unit tests using smart pointers.
- **BankAccountSmartPointerParameterizedTest_4.cpp**: Parameterized unit tests using smart pointers.
- **CMakeLists.txt**: CMake configuration file for building the project and running tests.

## Getting Started

### Prerequisites

- CMake 3.10 or higher
- Google Test library
- A C++ compiler that supports C++11

### Building the Project

1. Clone the repository:
    ```sh
    git clone git@github.com:denkhzol/GTestBankAccountScenarios.git
    cd GTestBankAccountScenarios
    ```

2. Create a build directory and navigate into it:
    ```sh
    mkdir build
    cd build
    ```

3. Run CMake to configure the project:
    ```sh
    cmake ..
    ```

4. Build the project:
    ```sh
    make
    ```

### 1. Running the Demo Application

After building the project, you can run the demo application:

```sh
./demoApp
```

### Running the Unit Tests

**2. Test Fixture with Traditional Pointer:** `BankAccountPointerTest_2` uses a traditional pointer to manage the BankAccount instance.
To run the unit tests, execute the following command in the build directory:

```sh
./unitTestPointer
```

**3. Test Fixture with Smart Pointer**: `BankAccountSmartPointerTest_3` uses a smart pointer (`std::unique_ptr`) for automatic memory management. 
To run the unit tests with smart pointers, execute:

```sh
./unitTestSmartPointer
```

**4. Parameterized Test**: `BankAccountSmartPointerParameterizedTest_4` runs the `MultipleInputs` test with different sets of deposit and withdrawal parameters. 
To run the unit tests with parameters, execute:

```sh
./unitTestParameterized
```

## Files Overview

### BankAccount.hpp
Defines the `BankAccount` class with methods for depositing, withdrawing, checking balance, and transferring funds. It includes both traditional and smart pointer versions of the transfer method.

### BankAccount.cpp
Implements the methods declared in `BankAccount.hpp`. It includes basic functionality for depositing, withdrawing, and transferring funds, with appropriate console output for each operation.

### BankAccountDemo_1.cpp
A simple demonstration program that creates two `BankAccount` objects performs some operations on them and prints the results.

### BankAccountPointerTest_2.cpp
Contains unit tests using traditional pointers. It includes a test fixture class `BankAccountTestFixture` and several test cases to verify the functionality of the `BankAccount` class.

### BankAccountSmartPointerTest_3.cpp
Similar to `BankAccountPointerTest_2.cpp`, but uses smart pointers (`std::unique_ptr` and `std::shared_ptr`) instead of traditional pointers.

### BankAccountSmartPointerParameterizedTest_4.cpp
Adds parameterized tests to the mix, allowing you to run the same test with different sets of parameters. This file uses a test fixture class `BankAccountParameterizedTestFixture` and defines multiple test cases with different input values.

## Acknowledgments

- Google Test (GTest) for the testing framework.
- CMake for the build system.
- Others