#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hp(10), _energy(10), _ad(0)
{
    std::cout << "ClapTrap: Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _energy(10), _ad(0)
{
    std::cout << "ClapTrap: Param constructor called" << std::endl;
    _name = name;
}

ClapTrap::ClapTrap(std::string name, int hp, int energy, int ad) : _name(name), _hp(hp), _energy(energy), _ad(ad)
{
    std::cout << "ClapTrap: All param constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
    std::cout << "ClapTrap: Copy constructor called" << std::endl;
    operator=(obj);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap: Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
    std::cout << "ClapTrap: Copy constructor called" << std::endl;
    if (&obj != this)
    {
        _name = obj._name;
        _hp = obj._hp;
        _energy = obj._energy;
        _ad = obj._ad;
    }
    return (*this);
}

void ClapTrap::attack(const std::string &target)
{
    if (_hp <= 0)
    {
        std::cout << _name << " is already dead" << std::endl;
        return;
    }
    if (_energy > 0)
    {
        std::cout << _name << " attacks " << target << " dealing " << _ad << " damages" <<std::endl;
        _energy--;
    }
    else
    {
        std::cout << _name << "has not enough energy" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hp <= 0)
    {
        std::cout << _name << " is already dead " << std::endl;
        return ;
    }
    _hp -= amount;
    std::cout << _name << " took " << amount << "damages" << std::endl;
    if (_hp <= 0)
    {
        std::cout << _name << " is dead " << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hp <= 0)
    {
        std::cout << _name << " is already dead" << std::endl;
        return ;
    }
    if (_energy > 0)
    {
        _energy--;
        _hp += amount;
        std::cout << _name << " has been repaired for " << amount << " hp" << std::endl;
    }
    else
    {
        std::cout << _name << "has not enough energy" << std::endl;
    }
}
