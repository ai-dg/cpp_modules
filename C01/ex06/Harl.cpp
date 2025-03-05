#include "Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void (Harl::*Harl::functions[4])(void) =
{
    &Harl::debug,
    &Harl::info,
    &Harl::warning,
    &Harl::error
};

const std::string Harl::levels[4] =
{
    "DEBUG",
    "INFO",
    "WARNING",
    "ERROR"
};

void Harl::complain(std::string level)
{


    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*functions[i])();
            return;
        }
    }

    std::cerr << "Unknown level" << std::endl;

}
