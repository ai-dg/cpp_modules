#include "Bureaucrat.hpp"
#include <string>
#include <stdexcept>
#include <iostream>

Bureaucrat::Bureaucrat() : name("Default"), _grade(150)
{
    std::cout << "Bureaucrat class has been created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int const grade) : name(name), _grade(grade)
{
    std::cout << "Bureaucrat class has been created" << std::endl;
    if (_grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    if (_grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const& src) : name(src.name), _grade(src._grade)
{
    std::cout << "Bureaucrat has been copied" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& src)
{
    if (this != &src)
    {
        // this->name = src.getName();
        this->_grade = src.getGrade();
    }
    std::cout << "Bureaucrat has been assigned" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat class has been destroyed" << std::endl;

}

void Bureaucrat::decrementGrade(void)
{
    if (_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade += 1;;
}

void Bureaucrat::incrementGrade(void)
{
    if (_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade -= 1;
}

void Bureaucrat::signForm(Form& f)
{
    try
    {
        f.beSigned(*this);
        std::cout << this->getName() << " signed " << f.getName() << std::endl;

    }
    catch(std::exception& e)
    {
        std::cout << this->getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

std::string const Bureaucrat::getName(void) const
{    
    return this->name;
}

int Bureaucrat::getGrade(void) const
{
    return this->_grade;
}

void Bureaucrat::setGrade(int const grade)
{
    this->_grade = grade;
}

const char*  Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;

    return out;
}