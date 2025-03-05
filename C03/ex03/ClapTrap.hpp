#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
    protected:
        std::string name;
        int hitPoints;
        int energyPoints;
        int attackDmg;

    public:
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &src);
        ClapTrap& operator=(ClapTrap const &src);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};


#endif