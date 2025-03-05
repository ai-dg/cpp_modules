#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form(std::string const& name, int gradeToSign, int gradeToExecute) : name(name), _isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cout << "Form class has been created" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Bureaucrat::GradeTooHighException();
    
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Bureaucrat::GradeTooLowException();
}

Form::Form(Form const& src) : name(src.name), _isSigned(src._isSigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
    std::cout << "Form class has been copied" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Bureaucrat::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Bureaucrat::GradeTooLowException();
}

Form& Form::operator=(Form const& src)
{
    if (this != &src)
    {
        this->_isSigned = src.isSigned();
    }
    std::cout << "Form class has been assigned" << std::endl;
    return *this;
}

Form::~Form()
{
    std::cout << "Form class has been destroyed" << std::endl;
}

void Form::beSigned(Bureaucrat const& b)
{
    if (b.getGrade() > gradeToSign)
        throw Form::GradeTooLowException();
    this->_isSigned = true;
}

bool Form::isSigned() const
{
    return this->_isSigned;
}

std::string Form::getName() const
{
    return this->name;
}

int Form::getGradeToSign() const
{
    return this->gradeToSign;
}

int Form::getGradeToExecute() const
{
    return this->gradeToExecute;
}


const char* Form::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade too high to sign!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Bureaucrat grade too low to sign!";
}

std::ostream& operator<<(std::ostream &out, Form const& f)
{
    out << "Form " << f.getName() << " is signed = ";

    if (f.isSigned())
        out << "true";
    else
        out << "false";

    out << ", grade to sign = " << f.getGradeToSign()
        << ", grade to execute = " << f.getGradeToExecute() << std::endl;

    return out;
}
