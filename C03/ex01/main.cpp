#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
    ScavTrap scav1("Scav1");
    ScavTrap scav2("Scav2");

    scav1.attack("Target1");
    scav2.takeDamage(15);
    scav2.attack("Target2");
    scav1.takeDamage(30);
    scav1.beRepaired(20);
    scav2.guardGate();

    return 0;
}
