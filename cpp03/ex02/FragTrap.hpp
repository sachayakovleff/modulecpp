#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : ClapTrap
{
    public:
        FragTrap();
        ~FragTrap();
        FragTrap(std::string name);
        FragTrap(std::string name, int hp, int energy, int ad);
        FragTrap &operator=(const FragTrap obj);
        void    highFivesGuys();
    private:
};

#endif