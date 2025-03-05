#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap: virtual public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap const& src);
        FragTrap& operator=(FragTrap const& src);
        ~FragTrap();
        
        void attack(const std::string& target);
        void highFivesGuys(void);

};

#endif