#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    Animal *array[20];
    int i = 0;

    std::cout << "====================" << std::endl;
    std::cout << "Creation des animaux" << std::endl;

    while (i < 10)
    {
        std::cout << i;
        array[i] = new Dog();
        i++;
    }
    while (i < 20)
    {
        std::cout << i;
        array[i] = new Cat();
        i++;
    }

    std::cout << "====================" << std::endl;
    std::cout << "Destruction des animaux" << std::endl;
    i = 0;
    while (i < 10)
    {
        std::cout << i;
        delete(array[i]);
        i++;
    }
    while (i < 20)
    {
        std::cout << i;
        delete(array[i]);
        i++;
    }
}