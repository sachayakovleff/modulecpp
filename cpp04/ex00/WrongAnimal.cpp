#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("")
{
    std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name) : _type(name)
{
    std::cout << "WrongAnimal: Param constructor called" << std::endl;
    _type = name;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
    std::cout << "WrongAnimal: Copy constructor called" << std::endl;
    operator=(obj);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal: Destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
    std::cout << "WrongAnimal: Copy constructor called" << std::endl;
    if (&obj != this)
        _type = obj._type;
    return (*this);
}

void WrongAnimal::makeSound() const
{
    std::cout << "Wrong animal sound" << std::endl;
}
