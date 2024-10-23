#include "PersonService.h"

PersonService::PersonService() {

}

//ctor to inject repository
PersonService::PersonService(PersonRepository personRepository) {
    this->personRepository = personRepository;
}

PersonService::~PersonService() {

}

void PersonService::setPerson(Person person) {
    this->personRepository.save(person);
}

std::vector<Person> PersonService::getAllPersons() {
    return this->personRepository.findAll();
}
