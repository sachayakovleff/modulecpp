#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("", 100, 50, 20)
{
    std::cout << "ScavTrap: Contructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap: Destructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap: Param contructor called" << std::endl;
    _hp = 100;
    _energy = 50;
    _ad = 20;
}

ScavTrap::ScavTrap(std::string name, int hp, int energy, int ad) : ClapTrap(name, hp, energy, ad)
{
    std::cout << "ScavTrap: All param constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap obj)
{
    std::cout << "ScavTrap: Operator = called" << std::endl;
    _ad = obj._ad;
    _name = obj._name;
    _hp = obj._hp;
    _energy = obj._energy;
    return (*this);
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap: Gate keeper enabled" << std::endl;
}
