#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
    FragTrap frag1("Frag1");
    FragTrap frag2("Frag2");

    frag1.attack("Target1");
    frag2.takeDamage(15);
    frag2.attack("Target2");
    frag1.takeDamage(30);
    frag1.beRepaired(20);
    frag2.highFivesGuys();

    return 0;
}
