#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Brains have been created" << std::endl;
}

Brain::Brain(Brain const& src)
{
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = src.ideas[i];
    }
    std::cout << "Brains have been copied" << std::endl;

}

Brain& Brain::operator=(Brain const& src)
{
    if (this != &src)
    {
        for(int i = 0; i < 100; i ++)
        {
            this->ideas[i] = src.ideas[i];
        }
    }
    
    std::cout << "Brains have been assigned" << std::endl;

    return *this;
}

Brain::~Brain()
{
    std::cout << "Brains have been destroyed" << std::endl;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return this->ideas[index];

    return "";
}

void Brain::setIdea(int index, std::string idea)
{
    if (index >= 0 && index < 100)
        this->ideas[index] = idea;
}
