#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type) :  type(type)
{
    
}

Weapon::~Weapon()
{

}

const std::string& Weapon::getType(void) const
{
    return type;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}


