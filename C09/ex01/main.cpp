#include "RPN.hpp"
#include <iostream>

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./RPN <operation>" << std::endl;
        return 1;
    }
    RPN rpn;
    rpn.calculate(av[1]);
    // rpn.displayStack();
    rpn.displayResult();
    return 0;
}