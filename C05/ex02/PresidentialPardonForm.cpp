#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout << "PresidentialPardonForm has been created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src) : AForm(src), target(src.target)
{
    std::cout << "PresidentialPardonForm has been copied" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& src)
{
    if (this != &src)
    {
        this->target = src.target;
    }
    std::cout << "PresidentialPardonForm has been assigned" << std::endl;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm has been destroyed" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    checkExecution(executor);
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}