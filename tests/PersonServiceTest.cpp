// tests/PersonServiceTest.cpp

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Service/PersonService.h"
#include "Repository/IPersonRepository.h"

class MockPersonRepository : public IPersonRepository {
public:
    MOCK_METHOD(void, save, (Person& person), (override));
    MOCK_METHOD(std::vector<Person>, findAll, (), (override));
};

class PersonServiceTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Code here will be called immediately after the constructor (right before each test).
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right before the destructor).
    }

    MockPersonRepository mockRepository;
    PersonService service{mockRepository};
};


TEST_F(PersonServiceTest, GetAllPersons) {
    //message to console running this test method
    std::cout << "Running test PersonServiceTest.GetAllPersons" << std::endl;
    std::vector<Person> persons = { Person("John Doe", 25), Person("Jane Doe", 27) };
    EXPECT_CALL(mockRepository, findAll()).WillOnce(::testing::Return(persons));
    auto result = service.getAllPersons();
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(result[0].getName(), "John Doe");
    EXPECT_EQ(result[0].getAge(), 25);
    EXPECT_EQ(result[1].getName(), "Jane Doe");
    EXPECT_EQ(result[1].getAge(), 27);
}

// Add more tests as needed
