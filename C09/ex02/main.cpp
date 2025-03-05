#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>

int main(int ac, char** av)
{
    if (ac < 2)
    {
        std::cerr << "Usage: ./PmergeMe <number1> <number2> <number3> ..." << std::endl;
        return 1;
    }
    PmergeMe p;
    if (!p.checkValues(av))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    p.addValuesToContainers(av);
    p.mergeInsertSort();
    return 0;
}
