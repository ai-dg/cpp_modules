#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
    std::cout << "------------------- Test #1 -------------------" << std::endl;
    try 
    {
        Bureaucrat bob("Bob", 2);
        ShrubberyCreationForm form1("file");
        RobotomyRequestForm form2("Alice");
        PresidentialPardonForm form3("Charlie");

        std::cout << std::endl << "*******Shrubbery******" << std::endl << std::endl;
        bob.signForm(form1);
        bob.executeForm(form1);
        std::cout << std::endl;

        std::cout << std::endl << "*********Robotomy*******" << std::endl << std::endl;
        bob.signForm(form2);
        bob.executeForm(form2);
        std::cout << std::endl;

        std::cout << std::endl << "**********Presidential*********" << std::endl << std::endl;
        bob.signForm(form3);
        bob.executeForm(form3);
        std::cout << std::endl;

    } 
    catch (std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "------------------- Test #2 -------------------" << std::endl;

    try
    {
        Bureaucrat chris("Chris", 150);
        ShrubberyCreationForm form1("test2");
        RobotomyRequestForm form2("Alice");
        PresidentialPardonForm form3("Trump");

        std::cout << std::endl << "*******Shrubbery******" << std::endl << std::endl;
        chris.signForm(form1);
        chris.executeForm(form2);
        std::cout << std::endl;
        
        std::cout << std::endl << "*********Robotomy*******" << std::endl << std::endl;
        chris.signForm(form2);
        chris.executeForm(form2);
        std::cout << std::endl;

        std::cout << std::endl << "**********Presidential*********" << std::endl << std::endl;
        chris.signForm(form3);
        chris.executeForm(form3);
        std::cout << std::endl;


    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----------------------------------------------" << std::endl;
    return 0;
}
