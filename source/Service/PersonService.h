#pragma once

#include "IPersonService.h"
#include "../Repository/PersonRepository.h"
#include <vector>
#include <memory>


class PersonService : public IPersonService {
  public:
    PersonService();
    explicit PersonService(std::unique_ptr<IPersonRepository> personRepository);
    ~PersonService() override;
    void setPerson(Person person) override;
    std::vector<Person> getAllPersons() override;
  private:
    std::unique_ptr<IPersonRepository> personRepository;

};

