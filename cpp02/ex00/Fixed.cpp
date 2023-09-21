#include "Fixed.hpp"

const int Fixed::bit_number;

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(const Fixed &object)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = object;
    this->value = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const &object)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (&object != this)
        this->value = object.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

void Fixed::setRawBits(int bits)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->value = bits;
}
