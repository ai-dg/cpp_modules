#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Animal: " << type << " has been created" << std::endl;
}

Dog::Dog(Dog const &src) : Animal(src)
{
    *this = src;
    std::cout << "Animal: " << type << " copied" << std::endl;
}

Dog& Dog::operator=(Dog const& src)
{
    if (this != &src)
    {
        Animal::operator=(src);
    }

    std::cout << "Animal: " << type << " has been assigned" << std::endl;

    return *this;
}

Dog::~Dog()
{
    std::cout << "Animal: " << type << " has been destroyed" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Animal says Woof!" << std::endl;
}
