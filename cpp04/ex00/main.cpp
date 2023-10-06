#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    Animal *meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete(meta);
    delete(i);
    delete(j);

    WrongAnimal *wa = new WrongAnimal();
    WrongCat    *wc = new WrongCat();
    wa->makeSound();
    wc->makeSound();
    delete(wa);
    delete(wc);
return 0;
}