#include "Dog.hpp"

Dog::Dog()
{
    _type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
    this->brain = new Brain();
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
    std::cout << "Dog copy constructor called" << std::endl;
    operator=(obj);
}

Dog &Dog::operator=(const Dog &animal)
{
    if (this != &animal)
    {
        _type = animal._type;
        this->brain = animal.brain;
    }
    std::cout << "Dog operator constructor called" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog: Destructor called" << std::endl;
    delete(this->brain);
}

void Dog::makeSound() const
{
    std::cout << "waf" << std::endl;
}

