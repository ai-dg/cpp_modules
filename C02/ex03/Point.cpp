#include "Point.hpp"

Point::Point() : x(0), y(0)
{

}

Point::Point(const float x_alpha, const float y_alpha) : x(x_alpha), y(y_alpha)
{

}

Point::Point(Point const& src) : x(src.x), y(src.y)
{
}

Point::~Point()
{

}

Point& Point::operator=(Point const& src)
{
    if (this != &src)
    {
        const_cast<Fixed&>(this->x) = src.getX();
        const_cast<Fixed&>(this->y) = src.getY();
    }
    return *this;
}

Fixed Point::getX() const
{
    return this->x;
}

Fixed Point::getY() const
{
    return this->y;
}