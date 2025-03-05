#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("DefaultScav")
{
    hitPoints = 100;
    energyPoints = 50;
    attackDmg = 20;
    std::cout << "ScavTrap " << name << "has been created (default)" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDmg = 20;
    std::cout << "ScavTrap " << this->name << " has been created" << std::endl;
}
ScavTrap::ScavTrap(ScavTrap const& src) : ClapTrap(src)
{
    *this = src;
    std::cout << "ScavTrap " << this->name << " has been copied" << std::endl;

}

ScavTrap& ScavTrap::operator=(ScavTrap const &src)
{
    if (this != &src)
    {
        ClapTrap::operator=(src);
    }
    
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->name << " has been destroyed" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (energyPoints > 0 && hitPoints > 0)
   {
        std::cout << "Scavtrap " << name << " attacks " << target << ", causing " << this->attackDmg << " points of damage!" << std::endl;
        energyPoints--;
   }
   else
   {
        std::cout << "Scavtrap " << name << " has no more energy to attack" << std::endl;
   }

}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}
