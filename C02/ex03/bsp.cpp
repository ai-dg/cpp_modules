#include "Point.hpp"
#include <iostream>

// Shoelace formula: Area = | x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2) | / 2.0
Fixed area(Point const p1, Point const p2, Point const p3)
{
    Fixed result;
    result = (p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat()) +
              p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat()) +
              p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat())) / 2.0f;



    return result.abs();
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed A = area(a, b, c);
    Fixed A1 = area(point, b, c);
    Fixed A2 = area(a, point, c);
    Fixed A3 = area(a, b, point);
    Fixed total = A1 + A2 + A3;


    // std::cout << A.getRawBits() << std::endl;
    // std::cout << A1.getRawBits() << std::endl;
    // std::cout << A2.getRawBits() << std::endl;
    // std::cout << A3.getRawBits() << std::endl;
    // std::cout << total.getRawBits() << std::endl;


    return (A == total);

}
