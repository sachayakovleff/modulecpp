#include "Fixed.hpp"
#include <math.h>

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
}

Fixed::Fixed(int integer)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = integer << bit_number;
}

Fixed::Fixed(float floating)
{
    std::cout << "Float constructor called" << std::endl;
	this->value = (int)roundf(floating * (1 << bit_number));
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
    //std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

void Fixed::setRawBits(int bits)
{
    //std::cout << "setRawBits member function called" << std::endl;
    this->value = bits;
}

int Fixed::toInt(void) const
{
    return (this->value >> bit_number);
}

float Fixed::toFloat(void) const
{
    return (float)this->value / (float)(1 << bit_number);
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
    os << obj.toFloat();
    return os;
}
