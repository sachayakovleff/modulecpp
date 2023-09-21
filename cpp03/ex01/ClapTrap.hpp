#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(std::string);
        ClapTrap(std::string name, int hp, int energy, int ad);
        ClapTrap(const ClapTrap &obj);
        ~ClapTrap();
        ClapTrap &operator=(const ClapTrap &obj);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    protected:
        std::string _name;
        int         _hp;
        int         _energy;
        int         _ad;
};

#endif