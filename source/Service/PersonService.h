#pragma once

#include "IPersonService.h"
#include "../Repository/PersonRepository.h"
#include <vector>

class PersonService : public IPersonService {
  public:
    PersonService();
    PersonService(IPersonRepository& personRepository);
    ~PersonService();
    void setPerson(Person person);
    std::vector<Person> getAllPersons();
  private:
    IPersonRepository& personRepository;

};

