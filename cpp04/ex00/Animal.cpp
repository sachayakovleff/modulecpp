#include "Animal.hpp"

Animal::Animal() : _type("")
{
    std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(std::string name) : _type(name)
{
    std::cout << "Animal: Param constructor called" << std::endl;
    _type = name;
}

Animal::Animal(const Animal &obj)
{
    std::cout << "Animal: Copy constructor called" << std::endl;
    operator=(obj);
}

Animal::~Animal()
{
    std::cout << "Animal: Destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &obj)
{
    std::cout << "Animal: Copy constructor called" << std::endl;
    if (&obj != this)
        _type = obj._type;
    return (*this);
}

void Animal::makeSound() const
{
    std::cout << "unknown noices" << std::endl;
}

std::string Animal::getType() const
{
    return _type;
}

