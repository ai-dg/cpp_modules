#include "AForm.hpp"
#include <iostream>

/**
 * @brief Public:
 */
AForm::AForm(std::string const& name, int gradeToSign, int gradeToExecute) : name(name), _isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    checkGrade();
    std::cout << "AForm class has been created" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Bureaucrat::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Bureaucrat::GradeTooLowException();
}

AForm::AForm(AForm const& src) : name(src.name), _isSigned(src._isSigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
    checkGrade();
    std::cout << "AForm class has been copied" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Bureaucrat::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Bureaucrat::GradeTooLowException();
}

AForm& AForm::operator=(AForm const& src)
{
    if (this != &src)
    {
        this->_isSigned = src.isSigned();
    }
    checkGrade();
    std::cout << "AForm class has been assigned" << std::endl;
    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm class has been destroyed" << std::endl;
}

void AForm::beSigned(Bureaucrat const& b)
{
    if (b.getGrade() > gradeToSign)
        throw AForm::GradeTooLowException();
    this->_isSigned = true;
}

bool AForm::isSigned() const
{
    return this->_isSigned;
}

std::string AForm::getName() const
{
    return this->name;
}

int AForm::getGradeToSign() const
{
    return this->gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return this->gradeToExecute;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade too high to sign!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Bureaucrat grade too low to sign!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

std::ostream& operator<<(std::ostream &out, AForm const& f)
{
    out << "Form " << f.getName() << " is signed: ";

    if (f.isSigned())
        out << "true";
    else
        out << "false";

    out << ", grade to sign = " << f.getGradeToSign()
        << ", grade to execute = " << f.getGradeToExecute() << std::endl;

    return out;
}

/**
 * @brief Private:
 */
void AForm::checkGrade() const
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();

}

/**
 * @brief Protected:
 */
void AForm::checkExecution(Bureaucrat const& executor) const
{
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
}
