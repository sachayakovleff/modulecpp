#include "Harl.hpp"

Harl::Harl()
{
    return ;
}

Harl::~Harl()
{
    return ;
}

void Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
    info();
}

void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger !";
    std::cout << "If you did, I wouldn’t be asking for more !" << std::endl;
    warning();
}

void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming";
    std::cout << "for years whereas you started working here since last month." << std::endl;
    error();
}

void Harl::error()
{
    std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    FunctionHandler functions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while (i < 4)
    {
        if (level == levels[i])
        {
            (this->*(functions[i]))();
            return ;
        }
        i++;
    }
    std::cout << "Invalid level" << std::endl;
}
