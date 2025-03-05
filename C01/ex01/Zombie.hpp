#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
    public:
        Zombie();
        ~Zombie();

        void setName(std::string name);
        void announce(void) const;

    private:
        std::string name;
};

#endif