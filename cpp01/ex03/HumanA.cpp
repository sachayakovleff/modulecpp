#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)  : name(name), weapon(weapon)
{
    this->name = name;
	this->weapon = weapon;
}

HumanA::~HumanA()
{

}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with his " << this->weapon.getType();
	std::cout << std::endl;
}
