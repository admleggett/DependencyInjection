#pragma once

#include "../Model/Person.h"
#include <vector>

class IPersonService {
  public:
    virtual void setPerson(Person person) = 0;
    virtual std::vector<Person> getAllPersons() = 0;
};
