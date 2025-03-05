#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("DefaultFrag")
{
    hitPoints = 100;
    energyPoints = 100;
    attackDmg = 30;
    std::cout << "FragTrap " << "DefaultFrag" << " has been created" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDmg = 30;
    std::cout << "FragTrap " << this->name << " has been created" << std::endl;

}
FragTrap::FragTrap(FragTrap const& src) : ClapTrap(src)
{
    *this = src;
    std::cout << "FragTrap " << this->name << " has been copied" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const& src)
{
    if (this != &src)
    {
        ClapTrap::operator=(src);
    }
    std::cout << "FragTrap " << this->name << " has been assigned" << std::endl;

    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->name << " has been destroyed" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        std::cout << "FragTrap " << name << " attacks " << target << ", causing " << this->attackDmg << " points of damage!" << std::endl;
        energyPoints--;
    }
    else
    {
        std::cout << "FragTrap " << name << " has no more energy to attack" << std::endl;
    }
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << " requests: High fives, guys!" << std::endl;
}
