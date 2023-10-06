#include "Cat.hpp"

Cat::Cat()
{
    Animal::_type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
    std::cout << "Cat copy constructor called" << std::endl;
    operator=(obj);
}

Cat &Cat::operator=(const Cat &obj)
{
    std::cout << "Cat: Copy constructor called" << std::endl;
    if (&obj != this)
        _type = obj._type;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat: Destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "miaw" << std::endl;
}
