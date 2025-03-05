#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() 
{
    try 
    {
        std::cout << "-----------------------------------Test #1------------------------------" << std::endl;
        Bureaucrat bob("Bob", 2);
        Intern intern;

        std::cout << "-----------------Shrubberry Creation---------------" << std::endl;
        AForm* form1 = intern.makeForm("shrubbery creation", "file");
        if (form1) 
        {
            bob.signForm(*form1);
            bob.executeForm(*form1);
            delete form1;
        }
        std::cout << "---------------------------------------------------" << std::endl;

        std::cout << "-------------------Robotomy Request----------------" << std::endl;
        AForm* form2 = intern.makeForm("robotomy request", "Alice");
        if (form2) 
        {
            bob.signForm(*form2);
            bob.executeForm(*form2);
            delete form2;
        }

        std::cout << "---------------------------------------------------" << std::endl;
        std::cout << "-----------------Presidential Pardon---------------" << std::endl;
        AForm* form3 = intern.makeForm("presidential pardon", "Charlie");
        if (form3) 
        {
            bob.signForm(*form3);
            bob.executeForm(*form3);
            delete form3;
        }

        std::cout << "---------------------------------------------------" << std::endl;
        std::cout << "--------------------Unknown form-------------------" << std::endl;
        AForm* form4 = intern.makeForm("unknown form", "Unknown");
        if (form4) 
        {
            delete form4;
        }
        std::cout << "---------------------------------------------------" << std::endl;
    } 
    catch (std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
    }
    
    try 
    {
        std::cout << "-----------------------------------Test #2------------------------------" << std::endl;
        Bureaucrat bob("Alice", 150);
        Intern intern;

        std::cout << "-----------------Shrubberry Creation---------------" << std::endl;
        AForm* form1 = intern.makeForm("shrubbery creation", "home");
        if (form1) 
        {
            bob.signForm(*form1);
            bob.executeForm(*form1);
            delete form1;
        }
        std::cout << "---------------------------------------------------" << std::endl;

        std::cout << "-------------------Robotomy Request----------------" << std::endl;
        AForm* form2 = intern.makeForm("robotomy request", "Alice");
        if (form2) 
        {
            bob.signForm(*form2);
            bob.executeForm(*form2);
            delete form2;
        }

        std::cout << "---------------------------------------------------" << std::endl;
        std::cout << "-----------------Presidential Pardon---------------" << std::endl;
        AForm* form3 = intern.makeForm("presidential pardon", "Charlie");
        if (form3) 
        {
            bob.signForm(*form3);
            bob.executeForm(*form3);
            delete form3;
        }

        std::cout << "---------------------------------------------------" << std::endl;
        std::cout << "--------------------Unknown form-------------------" << std::endl;
        AForm* form4 = intern.makeForm("unknown form", "Unknown");
        if (form4) 
        {
            delete form4;
        }
        std::cout << "---------------------------------------------------" << std::endl;
    } 
    catch (std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
    }


    return 0;
}