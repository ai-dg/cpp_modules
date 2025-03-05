#include <iostream>
#include "iter.hpp"
#include <string>

int main(void)
{
    int intArray[] = {1, 2, 3, 4, 5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    std::string strArray[] = {"ordinateur", "clavier", "4k", "IA", "certificat"};     

    std::cout << "------------------------Int array------------------" << std::endl;

    iter(intArray, 5, printElements);
    std::cout << std::endl;
    
    std::cout << "------------------------Char array------------------" << std::endl;

    iter(charArray, 5, printElements);
    std::cout << std::endl;

    std::cout << "------------------------String array------------------" << std::endl;

    iter(strArray, 5, printElements);
    std::cout << std::endl;
}
