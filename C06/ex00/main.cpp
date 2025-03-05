#include "ScalarConverter.hpp"
#include <string>
#include <iostream>

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: " << av[0] << " <literal>" << std::endl;
        return 1;
    }

    ScalarConverter::convert(av[1]);


    
}