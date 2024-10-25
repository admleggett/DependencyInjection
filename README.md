# Dependency Injection

Dependency Injection is a design pattern that allows us to remove the hard-coded dependencies and make our application loosely coupled, extendable and maintainable.
We can implement dependency injection to move the dependency resolution from compile-time to runtime.

This enables us to replace dependencies without changing the class that uses them. As a result, we can more easily test our classes in isolation, and we can more easily reuse our classes.

I'm well versed in the use of dependency injection in Java/Spring, but I wanted to understand how to make it work in C++.
So I decided to implement a simple example to demonstrate an approach and to enable unit testing using GMock.

I have created a simple Person/contacts example with model, service and repository interfaces/classes.

## Classes

1. `Person` - a simple model class with a name and an age.
2. `IPersonService` - an interface class that provides the functionality to retrieve all people and add a person to the list of contacts.
3. `PersonService` - a service class that implements `IPersonService`.
4. `IPersonRepository` - an interface class that provides the functionality to retrieve all people and add a person to a datastore. This
    interface is injected into the `PersonService` class via the constructor.
5. `PersonRepository` - a repository class implements `IPersonRepository`.
6. `PersonServiceTest` - a test class that uses GMock to test the `PersonService` class via a Mock implementation of `IPersonRepository`.

