#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "Creating a zombie named \"Zombie\"" << std::endl;
    this->name = "Zombie";
    return ;
}

Zombie::Zombie(std::string name)
{
    std::cout << "Creating a zombie named " << name << std::endl;
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
