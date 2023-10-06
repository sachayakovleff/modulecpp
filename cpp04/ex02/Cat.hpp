#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "brain.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat &obj);
        Cat &operator=(const Cat &animal);
        ~Cat();
        void makeSound() const;
    private:
        Brain *brain;
};

#endif