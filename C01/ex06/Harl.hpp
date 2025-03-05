#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
    public:
        Harl();
        ~Harl();
        void complain(std::string level);
        static void (Harl::*functions[4])(void);
        static const std::string levels[4];

    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);

};


#endif