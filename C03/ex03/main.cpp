#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
    DiamondTrap diamond("Diamond");

    diamond.attack("Target");
    diamond.takeDamage(30);
    diamond.beRepaired(20);
    diamond.whoAmI();
    diamond.highFivesGuys();
    diamond.guardGate(); 

    return 0;
}
