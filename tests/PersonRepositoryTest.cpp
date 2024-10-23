// tests/PersonRepositoryTest.cpp

#include <gtest/gtest.h>
#include "Repository/PersonRepository.h" // Adjust the path as necessary

class PersonRepositoryTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Code here will be called immediately after the constructor (right before each test).
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right before the destructor).
    }

    // Objects declared here can be used by all tests in the test case for PersonRepository.
    PersonRepository repository;
};

TEST_F(PersonRepositoryTest, Save) {

}

TEST_F(PersonRepositoryTest, FindAll) {

}

// Add more tests as needed//
// Created by Admin on 23/10/2024.
//
