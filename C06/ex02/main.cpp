#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Identify.hpp"
#include <iostream>

int main(void)
{
    Base* basePtr = generate();
    identify(basePtr);
    identify(*basePtr);

    delete basePtr;

    return 0;

}