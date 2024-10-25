#include <iostream>
#include "Repository/PersonRepository.h"
#include "Service/PersonService.h"

int main()
{
    std::cout << "Contacts" << std::endl;

    //create a concrete PersonRepository
    auto personRepository = PersonRepository();
    //inject into the service via ctor
    auto personService = PersonService(std::make_unique<PersonRepository>(personRepository));
    //get the list of persons from the service
    //print them out
    for (const std::vector<Person> persons = personService.getAllPersons(); Person person : persons) {
        std::cout << person.toString() << std::endl;
    }

    return 0;
}
