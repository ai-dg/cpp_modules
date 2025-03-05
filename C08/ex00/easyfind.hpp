#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <stdexcept>

class NotFoundException: public std::exception
{
    virtual const char* what() const throw()
    {
        return "Value not found in container";
    }
};

template < typename T >
typename T::iterator easyfind(T& values, int value)
{
    typename T::iterator it = values.begin();
    for (; it != values.end(); it++)
    {
        if (*it == value)
        {
            return it;
        }
    }
    throw NotFoundException();
}

#endif