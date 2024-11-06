cmake_minimum_required(VERSION 3.10)

# Set the project name
project(BankAccountTests)

# C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the source files to SOURCES
set(SOURCES
    BankAccount.cpp
    BankAccountDemo_1.cpp
)

# Add the source files to TEST_SOURCES_POINTER
set(TEST_SOURCES_POINTER
    BankAccount.cpp
    BankAccountPointerTest_2.cpp
)

# Add the source files to TEST_SOURCES_SMART_POINTER
set(TEST_SOURCES_SMART_POINTER
    BankAccount.cpp
    BankAccountSmartPointerTest_3.cpp
)

# Add the source files to TEST_SOURCES_SMART_POINTER_PARAMETERIZED
set(TEST_SOURCES_SMART_POINTER_PARAMETERIZED
    BankAccount.cpp
    BankAccountSmartPointerParameterizedTest_4.cpp
)


# executable for the main application
add_executable(demoApp ${SOURCES})

add_executable(unitTestPointer ${TEST_SOURCES_POINTER})
# Link the GoogleTest libraries
target_link_libraries(unitTestPointer ${GTEST_LIBRARIES} pthread)

add_executable(unitTestSmartPointer ${TEST_SOURCES_SMART_POINTER})
# Link the GoogleTest libraries
target_link_libraries(unitTestSmartPointer ${GTEST_LIBRARIES} pthread)

add_executable(unitTestParameterized ${TEST_SOURCES_SMART_POINTER_PARAMETERIZED})
# Link the GoogleTest libraries
target_link_libraries(unitTestParameterized ${GTEST_LIBRARIES} pthread)
