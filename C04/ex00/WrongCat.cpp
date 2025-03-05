#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "WrongAnimal: " << type << " has been created" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src)
{
    *this = src;
    std::cout << "WrongAnimal: " << type << " copied" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const &src)
{
    if (this != &src)
    {
        WrongAnimal::operator=(src);
    }

    std::cout << "WrongAnimal: " << type << " assigned" << std::endl;

    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongAnimal: " << type << " has been destroyed" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat makes a sound!" << std::endl;
}
