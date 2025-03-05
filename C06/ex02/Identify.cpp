#include "Identify.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void)
{
    std::srand(std::time(0));

    int randNum = std::rand() % 3;

    switch(randNum)
    {
        case 0:
            std::cout << "Generated: A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated: B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated: C" << std::endl;
            return new C();
        
        default:
            return NULL;
    }

}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << "Type: A" << std::endl;
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout << "Type: B" << std::endl;
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout << "Type: C" << std::endl;
    }
    else
        std::cout << "Unknown type" << std::endl;
}

// void identify(Base& p)
// {
//     if (dynamic_cast<A*>(&p))
//     {
//         std::cout << "Ty&pe: A" << std::endl;
//     }
//     else if (dynamic_cast<B*>(&p))
//     {
//         std::cout << "Type: B" << std::endl;
//     }
//     else if (dynamic_cast<C*>(&p))
//     {
//         std::cout << "Type: C" << std::endl;
//     }
//     else
//         std::cout << "Unknown type" << std::endl;
// }

void identify(Base& p) 
{
    try 
    {
        A& aRef = dynamic_cast<A&>(p);
        (void)aRef;
        std::cout << "Type: A" << std::endl;
        return;
    } 
    catch (...) 
    {

    }

    try 
    {
        B& bRef = dynamic_cast<B&>(p);
        (void)bRef;
        std::cout << "Type: B" << std::endl;
        return;
    } 
    catch (...) 
    {

    }

    try 
    {
        C& cRef = dynamic_cast<C&>(p);
        (void)cRef;
        std::cout << "Type: C" << std::endl;
        return;
    } 
    catch (...) 
    {

    }

    std::cout << "Unknown type" << std::endl;
}
