#ifndef ITER_HPP
#define ITER_HPP
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>

template < typename T >
void printElements(T const& element)
{
    std::cout << element << " ";
}

template < typename T>
void iter(T* array, size_t length, void (*function)(T const&))
{
    for(size_t i = 0; i < length; ++i)
    {
        function(array[i]);
    }

}

#endif