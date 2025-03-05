#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::cout << "RobotomyRequestForm has been created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src) : AForm(src), target(src.target)
{
    std::cout << "RobotomyRequestForm has been copied" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& src)
{
    if (this != &src)
    {
        AForm::operator=(src);
        this->target = src.target;
    }
    std::cout << "RobotomyRequestForm has been assigned" << std::endl;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm has been destroyed" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    checkExecution(executor);
    std::cout << "* Drilling noises *" << std::endl;
    std::srand(std::time(0));
    if (std::rand() % 2)
    {
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy on " << target << " failed." << std::endl;
    }
}
