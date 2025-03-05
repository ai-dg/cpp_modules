#include "Array.hpp"
#include <iostream>

template < typename T >
Array<T>::Array() : elements(NULL), length(0)
{
    std::cout << "Template array class object (NULL values) has been created" << std::endl;
}

template < typename T >
Array<T>::Array(unsigned int n) : elements(new T[n]), length(n)
{
    std::cout << "Template array class object has been created" << std::endl;
}

template < typename T >
Array<T>::Array(Array const& src) : elements(new T[src.length]), length(src.length)
{
    for (unsigned int i = 0; i < length; i++) 
    {
        elements[i] = src.elements[i];
    }
    std::cout << "Template array class object has been copied" << std::endl;
}

template < typename T>
Array<T>& Array<T>::operator=(Array const& src)
{
    if (this != &src)
    {
        delete[] elements;
        this->length = src.length;
        elements = new T[this->length];

        for (unsigned int i = 0; i < this->length; i++)
        {
            elements[i] = src.elements[i];
        }
    }
    std::cout << "Template array class object has been assigned" << std::endl;
    return *this;
}

template < typename T>
Array<T>::~Array()
{
    delete[] elements;
    std::cout << "Template array class object has been destroyed" << std::endl;
}

template < typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= length)
    {
        throw std::out_of_range("Index out of limits");
    }
    return elements[index];
}

template < typename T >
T const& Array<T>::operator[](unsigned int index) const
{
    if (index >= length)
    {
        throw std::out_of_range("Index out of limits");
    }
    return elements[index];
}

template < typename T>
unsigned int Array<T>::size() const
{
    return length;
}
