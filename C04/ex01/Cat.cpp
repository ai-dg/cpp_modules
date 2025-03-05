#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Animal: " << this->type << " has been created" << std::endl;
}

Cat::Cat(Cat const& src) : Animal(src)
{
    this->brain = new Brain(*src.brain);
    std::cout << "Animal: " << this->type << " copied" << std::endl;
}

Cat& Cat::operator=(Cat const& src)
{
    if (this != &src)
    {
        Animal::operator=(src);
        delete this->brain;
        this->brain = new Brain(*src.brain);
    }

    std::cout << "Animal: " << this->type << " has been assigned" << std::endl;

    return *this;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Animal: " << this->type << " has been destroyed" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "Animal says Meow!" << std::endl;
}

Brain* Cat::getBrain() const
{
    return brain;
}
