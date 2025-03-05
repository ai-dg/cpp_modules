#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDmg(0)
{
    std::cout << "ClapTrap " << this->name << " has been created" << std::endl;

}

ClapTrap::ClapTrap(ClapTrap const &src) : name(src.name), hitPoints(src.hitPoints), energyPoints(src.energyPoints), attackDmg(src.attackDmg)
{
    std::cout << "ClapTrap " << this->name << " has been copied" << std::endl;
}


ClapTrap& ClapTrap::operator=(ClapTrap const &src)
{
    if (this != &src)
    {
        this->name = src.name;
        this->hitPoints = src.hitPoints;
        this->energyPoints = src.energyPoints;
        this->attackDmg = src.attackDmg;
    }
    std::cout << "ClapTrap " << this->name << " has been assigned" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " has been destroyed" << std::endl;

}

void ClapTrap::attack(const std::string& target)
{
   if (energyPoints > 0 && hitPoints > 0)
   {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << this->attackDmg << " points of damage!" << std::endl;
        energyPoints--;
   }
   else
   {
        std::cout << "ClapTrap " << name << " has no more energy to attack" << std::endl;
   }


}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints > 0)
    {
        if (hitPoints > (int)amount)
            hitPoints -= amount;
        else
            hitPoints = 0;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage. Hit points remaining: " << hitPoints << std::endl; 

    }
    else
    {
        std::cout << "ClapTrap " << name << " has not hit points left!" << std::endl;
    }

}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints > 0)
    {
        hitPoints += amount;
        energyPoints--;
        std::cout << "ClapTrap " << name << " repairs " << amount << " hit points, Hit points remaining: " << hitPoints << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << name << " has no more energy to be repaired" << std::endl;
    }

}

