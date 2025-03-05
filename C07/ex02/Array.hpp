#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <stdexcept>

template < typename T>
class Array
{
    private:
        T* elements;
        unsigned int length;

    public:
        Array();
        Array(unsigned int n);
        Array(Array const& src);
        Array& operator=(Array const& src);
        ~Array();

        T& operator[](unsigned int index);
        T const& operator[](unsigned int index) const;
        unsigned int size() const;
        


};

#include "Array.tpp"
#endif