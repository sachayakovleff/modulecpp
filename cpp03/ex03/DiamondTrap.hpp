#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    public:
        DiamondTrap();
        ~DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(std::string name, int hp, int energy, int ad);
        DiamondTrap &operator=(const DiamondTrap obj);
        void whoami();
        void attack(std::string &target);
    private:
        std::string _name;
};

#endif