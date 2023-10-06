#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    WrongAnimal::_type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    operator=(obj);
}

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
    std::cout << "WrongCat: Copy constructor called" << std::endl;
    if (&obj != this)
        _type = obj._type;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat: Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    WrongAnimal::makeSound();
}
