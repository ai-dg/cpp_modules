#include "MutantStack.hpp"
#include <iostream>

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
    std::cout << "MutantStack class object has been created" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const& src) : std::stack<T>(src)
{
    std::cout << "MutantStack class object has been copied" << std::endl;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack const& src)
{
    if (this != &src)
    {
        std::stack<T>::operator=(src);
    }
    std::cout << "MutantStack class object has been assigned" << std::endl;
    return *this;

}

template <typename T>
MutantStack<T>::~MutantStack()
{
    std::cout << "MutantStack class object has been destroyed" << std::endl;

}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (std::stack<T>::c.end());

}
