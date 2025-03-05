#ifndef POINT_HPP
# define POINT_HPP
#include "Fixed.hpp"

class Point
{
    private:
        Fixed const x;
        Fixed const y;

    public:
        Point();
        Point(const float x_alpha, const float y_alpha);
        Point(Point const& src);
        Point& operator=(Point const& src);
        ~Point();


        Fixed getX() const;
        Fixed getY() const;

};

#endif