#include "whatever.hpp"
#include <string>
#include <iostream>

int main(void)
{
    int a = 10;
    int b = 20;

    char c1 = 'c';
    char d1 = 'd';

    std::cout << "------------Original values-----------" << std::endl;

    std::cout << "a value: " << a << std::endl;
    std::cout << "b value: " << b << std::endl;
    std::cout << "c value: " << c1 << std::endl;
    std::cout << "d value: " << d1 << std::endl;


    ::swap(a, b);
    ::swap(c1, d1);

    std::cout << "------------Swap values---------------" << std::endl;

    std::cout << "a value: " << a << std::endl;
    std::cout << "b value: " << b << std::endl;
    std::cout << "c value: " << c1 << std::endl;
    std::cout << "d value: " << d1 << std::endl;

    std::cout << "------------Min values----------------" << std::endl;

    std::cout << "a value: " << a << std::endl;
    std::cout << "b value: " << b << std::endl;
    std::cout << "min value: " << ::min(a, b) << std::endl;

    std::cout << "c value: " << c1 << std::endl;
    std::cout << "d value: " << d1 << std::endl;
    std::cout << "min value: " << ::max(c1, d1) << std::endl;

    std::cout << "------------Max values----------------" << std::endl;
    
    std::cout << "a value: " << a << std::endl;
    std::cout << "b value: " << b << std::endl;
    std::cout << "max value: " << ::max(a, b) << std::endl;
    std::cout << "c value: " << c1 << std::endl;
    std::cout << "d value: " << d1 << std::endl;
    std::cout << "max value: " << ::max(c1, d1) << std::endl;
    
    std::cout << "------------42 tests------------------" << std::endl;
    a = 2;
    b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    
    return 0;

}

