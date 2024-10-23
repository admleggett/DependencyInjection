#pragma once
#include <string>
class Person {

  public:
    Person();
    Person(std::string name, int age);
    ~Person();
    std::string getName();
    void setName(std::string name);
    int getAge();
    void setAge(int age);
    std::string toString();

  private:
    std::string name;
    int age;
};

