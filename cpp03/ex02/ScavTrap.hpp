#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ~ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(std::string name, int hp, int energy, int ad);
        ScavTrap &operator=(const ScavTrap obj);
        void    guardGate();
    protected:
};

#endif