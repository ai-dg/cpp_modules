#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), name("Default")
{
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDmg = FragTrap::attackDmg;
    std::cout << "DiamondTrap " << name << " has been created (default)" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), name(name)
{
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDmg = FragTrap::attackDmg;
    std::cout << "DiamondTrap " << this->name << " has been created" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) :  ClapTrap(src), ScavTrap(src), FragTrap(src), name(src.name)
{
    *this = src;
    std::cout << "DiamondTrap " << this->name << " has been copied" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& src)
{
    if (this != &src)
    {
        ClapTrap::operator=(src);
        name = src.name;
    }

    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->name << " has been destroyed" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << this->name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}
