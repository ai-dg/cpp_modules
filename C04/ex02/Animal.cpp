#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Default")
{
    std::cout << "Animal: " << type << " has been created" << std::endl;
}

Animal::Animal(Animal const& src) : type(src.type)
{
    std::cout << "Animal copied" << std::endl;
}

Animal& Animal::operator=(Animal const& src)
{
    if (this != &src)
    {
        this->type = src.type;
    }
    std::cout << "Animal has been assigned" << std::endl;

    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal: " << type << " has been destroyed" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << "Some animal make a sound!" << std::endl;

}
