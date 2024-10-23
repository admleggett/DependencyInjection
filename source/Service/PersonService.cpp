#include "PersonService.h"
#include "PersonRepository.h"

PersonService::PersonService()
    : personRepository(*(new PersonRepository()))
{

}

//ctor to inject repository
PersonService::PersonService(IPersonRepository& personRepository):
    personRepository(personRepository) {

}

PersonService::~PersonService() {
    // Clean up the dynamically allocated repository if it was created by the default constructor
    if (dynamic_cast<PersonRepository*>(&personRepository)) {
        delete &personRepository;
    }
}

void PersonService::setPerson(Person person) {
    this->personRepository.save(person);
}

std::vector<Person> PersonService::getAllPersons() {
    return this->personRepository.findAll();
}
