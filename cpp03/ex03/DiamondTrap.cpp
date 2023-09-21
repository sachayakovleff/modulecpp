#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("_clap_name", 100, 50, 30)
{
    std::cout << "DiamondTrap: Constructor called" << std::endl;
    _hp = FragTrap::_hp;
    _energy = ScavTrap::_energy;
    _ad = FragTrap::_ad;
    _name = "";
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap: Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name", 100, 50, 30)
{
    std::cout << "DiamondTrap: Param contructor called" << std::endl;
    this->_name = name; 
}

DiamondTrap::DiamondTrap(std::string name, int hp, int energy, int ad) : ClapTrap(name + "_clap_name", hp, energy, ad)
{
    std::cout << "DiamondTrap: All params contructor called" << std::endl;
    _name = name;
    _hp = hp;
    _energy = energy;
    _ad = ad;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap obj)
{
    std::cout << "DiamondTrap: Operator = called" << std::endl;
    if (this != &obj)
    {
        _name = obj._name;
        _hp = obj._hp;
        _energy = obj._energy;
        _ad = obj._ad;
    }
    return *this;
}

void DiamondTrap::whoami()
{
    std::cout << "DiamondTrap: Diamond name: " << _name << std::endl;
    std::cout << "DiamondTrap: Clap name: " << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(std::string &target)
{
    ScavTrap::attack(target);
}
