#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Invalid args" << std::endl;
        return (1);
    }
    Harl harl;

    std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while (i < 4)
    {
        if (av[1] == levels[i])
        {
            break;
        }
        i++;
    }

    switch (i)
    {
        case 0 :
            harl.complain("DEBUG");
            break ;
        case 1 :
            harl.complain("INFO");
            break ;
        case 2 :
            harl.complain("WARNING");
            break ;
        case 3 :
            harl.complain("ERROR");
            break ;
        default :
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}