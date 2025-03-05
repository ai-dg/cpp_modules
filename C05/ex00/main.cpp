#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

int main(void)
{
    std::cout << "--------------Bob test case----------------" << std::endl;
    try
    {
        Bureaucrat bob("Bob" , 2);

        std::cout << bob;
        bob.incrementGrade();
        std::cout << bob;
        bob.incrementGrade(); 
        std::cout << bob;
    }
    catch (std::exception& e)
    {

        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;

    std::cout << "--------------Alice test case--------------" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 151);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
        std::cout << "-------------------------------------------" << std::endl;

    std::cout << "--------------Ralph test case--------------" << std::endl;
    try
    {
        Bureaucrat ralph("Ralph", 20);
        
        std::cout << ralph;
        
        ralph.incrementGrade();

        std::cout << ralph;

        ralph.decrementGrade();
        
        std::cout << ralph;

        ralph.decrementGrade();
        std::cout << ralph;

    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;

    }
    std::cout << "-------------------------------------------" << std::endl;
    
    return (0);

}