#pragma once

// repository interface to read/write person data

#include "../Model/Person.h"
#include <vector>

class IPersonRepository {
  public:
    virtual void save(Person person) = 0;
    virtual std::vector<Person> findAll() = 0;
};