#include "PersonRepository.h"
#include <iostream>


PersonRepository::PersonRepository() {
}

PersonRepository::~PersonRepository() {
}

void PersonRepository::save(Person person) {
    //output saving message to console
    std::cout << "Saving person to database" << std::endl;
}


std::vector<Person> PersonRepository::findAll() {
    //output reading all persons message to console
    std::cout << "Reading all persons from database" << std::endl;
    //hardcoded person objects
    auto persons = std::vector<Person>();
    persons.push_back( Person( "John Doe", 25 ) );
    persons.push_back( Person( "Jane Doe", 30 ) );
    return persons;
}
