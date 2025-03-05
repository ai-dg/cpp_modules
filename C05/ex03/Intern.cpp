#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>

Intern::Intern()
{
    std::cout << "Intern class has been created" << std::endl;
}

Intern::Intern(Intern const& src)
{
    (void)src;
    std::cout << "Intern class has been copied" << std::endl;
}

Intern& Intern::operator=(Intern const& src)
{
    (void)src;
    std::cout << "Intern class has been assigned" << std::endl;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern class has been destroyed" << std::endl;
}

AForm* Intern::makeForm(std::string const& formName, std::string const& target) const
{
    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    AForm* (Intern::*formCreators[3])(std::string const& target) const =
    {
        &Intern::makeShrubberyCreationForm,
        &Intern::makeRobotomyRequestForm,
        &Intern::makePresidentialPardonForm,
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == forms[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formCreators[i])(target);
        }
    }
    std::cout << "Intern could not find the form: " << formName << std::endl;
    return NULL;

}

AForm* Intern::makeShrubberyCreationForm(std::string const& target) const
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyRequestForm(std::string const& target) const
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialPardonForm(std::string const& target) const
{
    return new PresidentialPardonForm(target);
}
