#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): _fixedPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
    return;

}

Fixed::Fixed(Fixed const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed()
{
    std::cout << "Desctructor called" << std::endl;
}


Fixed& Fixed::operator=(Fixed const& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    
    if (this != &rhs)
    {
        this->_fixedPoint = rhs.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
    _fixedPoint = raw;
}
