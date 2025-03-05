#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <stdexcept>
#include <iostream>
#include <string>

int main(void)
{
    std::cout << "-------------Test #1-------------" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 50);
        Form formA("FormA", 75, 45);

        std::cout << alice << std::endl;
        std::cout << formA << std::endl;

        alice.signForm(formA);
        alice.decrementGrade();
        alice.decrementGrade();

        std::cout << alice << std::endl;
        alice.signForm(formA);

        std::cout << formA << std::endl;

    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "-------------Test #2-------------" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 50);
        Form formA("FormA", 1, 10);
        
        std::cout << alice << std::endl;
        std::cout << formA << std::endl;

        alice.signForm(formA);
        alice.decrementGrade();
        alice.decrementGrade();

        std::cout << alice << std::endl;
        alice.signForm(formA);

        std::cout << formA << std::endl;

    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "-------------Test #3-------------" << std::endl;
    try
    {
        Form formA("FormA", 151, 2);
        std::cout << formA << std::endl;

    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "-------------Test #4-------------" << std::endl;
    try
    {
        Form formA("FormA", 0, 2);
        std::cout << formA << std::endl;

    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "-------------Test #5-------------" << std::endl;
    try
    {
        Form formA("FormA", 2, 151);
        std::cout << formA << std::endl;

    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "-------------Test #6-------------" << std::endl;
    try
    {
        Form formA("FormA", 2, 0);
        std::cout << formA << std::endl;

    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);

}