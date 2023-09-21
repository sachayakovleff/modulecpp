#include "Fixed.hpp"
#include <math.h>

const int Fixed::bit_number;

Fixed::Fixed()
{
    // std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(const Fixed &object)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = object;
}

Fixed::Fixed(const int integer)
{
    // std::cout << "Int constructor called" << std::endl;
    this->value = integer << bit_number;
}

Fixed::Fixed(const float floating)
{
    //std::cout << "Float constructor called" << std::endl;
	this->value = roundf(floating * (1 << bit_number));
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const &object)
{
    //std::cout << "Copy assignment operator called" << std::endl;

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
    return (float)this->value / (1 << bit_number);
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
    os << obj.toFloat();
    return os;
}

bool Fixed::operator> (Fixed const &obj) const
{
    return this->getRawBits() > obj.getRawBits();
}

bool Fixed::operator>=(Fixed const &obj) const
{
    return this->getRawBits() >= obj.getRawBits();
}

bool Fixed::operator<(Fixed const &obj) const
{
    return this->getRawBits() < obj.getRawBits();
}

bool Fixed::operator<=(Fixed const &obj) const
{
    return this->getRawBits() <= obj.getRawBits();
}

bool Fixed::operator==(Fixed const &obj) const
{
    return this->getRawBits() == obj.getRawBits();
}

bool Fixed::operator!=(Fixed const &obj) const
{
    return this->getRawBits() != obj.getRawBits();
}

Fixed Fixed::operator+(Fixed const &obj) const
{
    Fixed res;

    res.setRawBits(this->getRawBits() + obj.getRawBits());
    return res;
}

Fixed Fixed::operator-(Fixed const &obj) const
{
     Fixed res;

    res.setRawBits(this->getRawBits() - obj.getRawBits());
    return res;
}

Fixed Fixed::operator*(Fixed const &obj) const
{
    Fixed res;

    res.setRawBits(this->getRawBits() * obj.getRawBits() >> bit_number);
    return res;
}

Fixed Fixed::operator/(Fixed const &obj) const
{
    Fixed res;

    res.setRawBits(this->getRawBits() / obj.getRawBits() >> bit_number);
    return res;
}

Fixed&	Fixed::operator++()  {
	this->value++;
	return *this;
}

Fixed	Fixed::operator++(int)  {
	Fixed	res(*this);
    operator++();
	return res;
}

Fixed&	Fixed::operator--()  {
	this->value--;
	return *this;
}

Fixed	Fixed::operator--(int)  {
	Fixed	res(*this);
    operator--();
	return res;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
    {
        return (b);
    }
    return a;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
    {
        return (a);
    }
    return b;
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
    if (a.getRawBits() > b.getRawBits())
    {
        return (b);
    }
    return a;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
    if (a.getRawBits() > b.getRawBits())
    {
        return (a);
    }
    return b;
}

