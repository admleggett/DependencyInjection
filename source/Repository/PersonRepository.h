#pragma once
#include "IPersonRepository.h"

class PersonRepository : public IPersonRepository {
  public:
    PersonRepository();
    ~PersonRepository();
    void save(Person& person);
    std::vector<Person> findAll();
};


