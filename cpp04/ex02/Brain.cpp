#include "brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &obj)
{
    std::cout << "Brain copy constructor called" << std::endl;
    operator=(obj);
}

Brain &Brain::operator=(const Brain &brain)
{
    int i = 0;

    std::cout << "Brain copy operator constructor called" << std::endl;
    if (this != &brain)
    {
        while (i < 100)
        {
            this->ideas[i] = brain.ideas[i];
            i++;
        }
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}
