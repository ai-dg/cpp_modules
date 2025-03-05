#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Animal: " << this->type << " has been created" << std::endl;
}

Cat::Cat(Cat const& src) : Animal(src)
{
    *this = src;
    std::cout << "Animal: " << this->type << " copied" << std::endl;
}

Cat& Cat::operator=(Cat const& src)
{
    if (this != &src)
    {
        Animal::operator=(src);
    }

    std::cout << "Animal: " << this->type << " has been assigned" << std::endl;

    return *this;
}

Cat::~Cat()
{
    std::cout << "Animal: " << this->type << " has been destroyed" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "Animal says Meow!" << std::endl;
}
