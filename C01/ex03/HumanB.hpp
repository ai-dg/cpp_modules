#ifndef HUMANB_CPP
# define HUMANB_CPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
    public:
        HumanB(std::string name);
        ~HumanB();

        void setWeapon(Weapon& club);
        void attack(void) const;
    
    private:
        Weapon* club;
        std::string name;

};

#endif