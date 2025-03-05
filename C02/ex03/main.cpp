#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main(void)
{
    Point const a(10.4f, 10.4f);
    Point const b(5.4f, 0);
    Point const c(20.8f, 0);
    Point const point(10.4f, 10.4f);

    if (bsp(a, b, c, point) == true)
    {
        std::cout << "The point is inside the triangle a, b, c." << std::endl;
    }
    else
    {
        std::cout << "The point is outside the triangle a, b, c." << std::endl;
        
    }

    return (0);

}
