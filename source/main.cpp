#include <iostream>
#include "Repository/PersonRepository.h"
#include "Service/PersonService.h"

int main()
{
    std::cout << "Contacts" << std::endl;

    //create a concrete PersonRepository
    PersonRepository personRepository = PersonRepository();
    //inject into the service via ctor
    PersonService personService = PersonService(personRepository);
    //get the list of persons from the service
    std::vector<Person> persons = personService.getAllPersons();
    //print them out
    for (Person person : persons) {
        std::cout << person.toString() << std::endl;
    }

    return 0;
}
