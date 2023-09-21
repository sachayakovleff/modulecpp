#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("", 100, 100, 30)
{
    std::cout << "FragTrap: Constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap: Destructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap: Param constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name, int hp, int energy, int ad) : ClapTrap(name, hp, energy, ad)
{
    std::cout << "FragTrap: All params constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap obj)
{
    std::cout << "FragTrap: operator = called" << std::endl;
    _ad = obj._ad;
    _name = obj._name;
    _hp = obj._hp;
    _energy = obj._energy;
    return (*this);
}

void FragTrap::highFivesGuys()
{
    std::cout << "HIGH FIVES !!" << std::endl;
}
