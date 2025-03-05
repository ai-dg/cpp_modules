#include "easyfind.hpp"
#include <vector>
#include <list>
#include <cstdlib>
#include <iostream>

int main(void)
{
    std::vector<int> vec;
    std::list<int> lst;

    for(int i = 0; i < 10; i++)
    {
        vec.push_back(i);
        lst.push_back(i);
    }

    std::cout << std::endl << "************** Tests **************" << std::endl;

    try
    {
        std::vector<int>::iterator vec_it = easyfind(vec, 3);
        std::cout << "Value found in vector: " << *vec_it << std::endl;

        std::list<int>::iterator list_it = easyfind(lst, 3);
        std::cout << "Value found in list: " << *list_it << std::endl;

        easyfind(vec, 20);
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

}