#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

int main(void) 
{
    std::cout << std::endl << "****************Test #1*************" << std::endl;
    try 
    {
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } 
    catch (std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "****************Test #2*************" << std::endl;

    try 
    {
        Span sp = Span(2);

        sp.addNumber(4);
        sp.addNumber(6);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } 
    catch (std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "****************Test #3*************" << std::endl;

    try 
    {
        Span sp = Span(1);

        sp.addNumber(5);

        // std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } 
    catch (std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "****************Test #4*************" << std::endl;

    try 
    {
        Span sp = Span(1);

        sp.addNumber(5);
        sp.addNumber(5);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } 
    catch (std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "****************Test #4*************" << std::endl;

    try 
    {
        std::srand(time(0));

        Span sp = Span(10);

        std::vector<int> vect1;
        for (int i = 0; i < 5; i++)
        {
            int number = std::rand() % 50;
            vect1.push_back(number);
        }
        sp.addNumbers(vect1.begin(), vect1.end());

        std::vector<int> vect2;
        for (int i = 0; i < 5; i++)
        {
            int number = std::rand() % 50;
            vect2.push_back(number);
        }
        sp.addNumbers(vect2.begin(), vect2.end());


        sp.printNumbers();

        std::vector<int> vect3;
        for (int i = 0; i < 5; i++)
        {
            int number = std::rand() % 50;
            vect3.push_back(number);
        }
        sp.addNumbers(vect3.begin(), vect3.end());

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } 
    catch (std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
