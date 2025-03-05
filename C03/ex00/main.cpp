#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
    ClapTrap clap1("Clap1");
    ClapTrap clap2("Clap2");

    clap1.attack("Clap2");
    clap2.takeDamage(5);
    clap2.attack("Clap1");
    clap1.takeDamage(3);
    clap1.beRepaired(4);
    clap2.attack("Clap1");
    clap1.beRepaired(8);
    for (int i = 0; i < 10; ++i) {
        clap2.attack("Clap1");
    }
    clap1.beRepaired(10);

    return 0;
}


