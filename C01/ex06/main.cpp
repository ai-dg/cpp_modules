#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: <log level>" << std::endl;
        return (1);
    }

    Harl harl;
    std::string level = av[1];
    int index = -1;

    for (int i = 0; i < 4; i++)
    {
        if (harl.levels[i] == level)
        {
            index = i;
            break;
        }
    }

    switch (index)
    {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            harl.complain("DEBUG");
            // fall through
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            harl.complain("INFO");
            // fall through
        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            harl.complain("WARNING");
            // fall through
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        
    }

    return (0);
}