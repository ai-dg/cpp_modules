#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(): _fixedPoint(0)
{
    // std::cout << "Default constructor called" << std::endl;
    return;

}

Fixed::Fixed(const int value)
{
    // std::cout << "Int constructor called" << std::endl;
    _fixedPoint = value << bits;
}

Fixed::Fixed(const float value)
{
    // std::cout << "Float constructor called" << std::endl;
    _fixedPoint = roundf(value * (1 << bits));
}

Fixed::Fixed(Fixed const &src)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed()
{
    // std::cout << "Desctructor called" << std::endl;
}


Fixed& Fixed::operator=(Fixed const& rhs)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    
    if (this != &rhs)
    {
        this->_fixedPoint = rhs.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return _fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
    _fixedPoint = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(_fixedPoint) / (1 << bits);
}

int Fixed::toInt(void) const
{
    return _fixedPoint >> bits;
}

std::ostream& operator<<(std::ostream& out, Fixed const &i)
{
    out << i.toFloat();
    
    return out;
}

bool Fixed::operator>(Fixed const &src) const
{
    return this->_fixedPoint > src._fixedPoint;
}

bool Fixed::operator<(Fixed const &src) const
{
    return this->_fixedPoint < src._fixedPoint;
}

bool Fixed::operator>=(Fixed const &src) const
{
    return this->_fixedPoint >= src._fixedPoint;
}

bool Fixed::operator<=(Fixed const &src) const
{
    return this->_fixedPoint <= src._fixedPoint;
}

bool Fixed::operator==(Fixed const &src) const
{
    return this->_fixedPoint == src._fixedPoint;    
}

bool Fixed::operator!=(Fixed const &src) const
{
    return this->_fixedPoint != src._fixedPoint;
}

Fixed Fixed::operator+(Fixed const &src) const
{
    Fixed result;
    result.setRawBits(this->_fixedPoint + src._fixedPoint);
    return result;
}

Fixed Fixed::operator-(Fixed const &src) const
{
    Fixed result;
    result.setRawBits(this->_fixedPoint - src._fixedPoint);
    return result;
}

Fixed Fixed::operator*(Fixed const &src) const
{
    Fixed result;
    result.setRawBits((this->_fixedPoint * src._fixedPoint) >> bits);
    return result;
}

Fixed Fixed::operator/(Fixed const &src) const
{
    Fixed result;
    result.setRawBits((this->_fixedPoint << bits) / src._fixedPoint);
    return result;
}

Fixed& Fixed::operator++()
{
    _fixedPoint += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    _fixedPoint += 1;
    return temp;
}

Fixed& Fixed::operator--()
{
    _fixedPoint -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    _fixedPoint -= 1;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    else
        return b;

}
const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
    if (a < b)
        return a;
    else
        return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    else
        return b;
}


const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
    if (a > b)
        return a;
    else
        return b;
}
Fixed Fixed::abs() const
{
    Fixed result = *this;

    if (result._fixedPoint < 0)
        result._fixedPoint = -result._fixedPoint;

    return result;
}
