#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Animal: " << type << " has been created" << std::endl;
}

Dog::Dog(Dog const &src) : Animal(src)
{
    this->brain = new Brain(*src.brain);
    std::cout << "Animal: " << type << " copied" << std::endl;
}

Dog& Dog::operator=(Dog const& src) {
    if (this != &src) 
    {
        Animal::operator=(src);
        delete this->brain;
        this->brain = new Brain(*src.brain);
    }
    std::cout << "Animal: " << this->type << " has been assigned" << std::endl;
    return *this;
}


Dog::~Dog()
{
    delete this->brain;
    std::cout << "Animal: " << type << " has been destroyed" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Animal says Woof!" << std::endl;
}


Brain* Dog::getBrain() const
{
    return brain;
}
