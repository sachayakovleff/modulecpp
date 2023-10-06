#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "brain.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog &obj);
        Dog &operator=(const Dog &animal);
        ~Dog();
        void makeSound() const;
    private:
        Brain *brain;
};

#endif