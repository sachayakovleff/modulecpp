#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    protected:
        Animal();
        Animal(std::string type);
        Animal(const Animal &obj);
        Animal &operator=(const Animal &animal);
        virtual ~Animal();
        virtual void makeSound() const;
        std::string getType() const;

    protected:
        std::string _type;
};

#endif