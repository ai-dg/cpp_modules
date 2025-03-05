#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : club(0), name(name)
{

}

HumanB::~HumanB()
{

}

void HumanB::setWeapon(Weapon& club)
{
    this->club = &club;
}

void HumanB::attack(void) const
{
    if (club)
    {
        std::cout << name << " attacks with their " << club->getType() << std::endl;
    }
    else
        std::cout << name << " has no weapon " << std::endl;
}

