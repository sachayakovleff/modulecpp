#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal &obj);
        WrongAnimal &operator=(const WrongAnimal &animal);
        virtual ~WrongAnimal();
        virtual void makeSound() const;
        std::string getType() const;
    protected:
        std::string _type;
};

#endif