#include "Person.h"

Person::Person() {
    name = "";
    age = 0;
}

Person::Person(std::string name, int age) {
    this->name = name;
    this->age = age;
}

Person::~Person() {
    // Destructor
}

std::string Person::getName() {
    return name;
}

void Person::setName(std::string name) {
    this->name = name;
}

int Person::getAge() {
    return age;
}

void Person::setAge(int age) {
    this->age = age;
}

std::string Person::toString() {
    return name + " is " + std::to_string(age) + " years old.";
}

