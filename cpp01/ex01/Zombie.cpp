#include "Zombie.hpp"

Zombie::Zombie()
{
    this->name = "Zombie";
    return ;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << this->name << " died" << std::endl;
}

void Zombie::announce( void )
{
    std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}
