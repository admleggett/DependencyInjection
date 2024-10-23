#include "PersonService.h"
#include "PersonRepository.h"

PersonService::PersonService()
    : personRepository(std::make_unique<PersonRepository>())
{

}

//ctor to inject repository
PersonService::PersonService(std::unique_ptr<IPersonRepository> personRepository):
    personRepository(std::move(personRepository)) {

}

PersonService::~PersonService() {

}

void PersonService::setPerson(Person person) {
    this->personRepository->save(person);
}

std::vector<Person> PersonService::getAllPersons() {
    return this->personRepository->findAll();
}
