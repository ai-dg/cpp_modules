#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal: " << type << " has been created" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& src)
{
    *this = src;
    std::cout << "WrongAnimal: " << type << " copied" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& src)
{
    if (this != &src)
    {
        this->type = src.type;
    }

    std::cout << "WrongAnimal: " << type << " assigned" << std::endl;

    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal: " << type << " has been destroyed" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal makes a sound!" << std::endl;
}
