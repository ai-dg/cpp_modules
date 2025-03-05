#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    // const Animal* meta = new Animal();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); 
    j->makeSound();

    delete j;
    delete i;

    return 0;
}
