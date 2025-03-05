#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <stdexcept>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const name;
        bool _isSigned;
        int const gradeToSign;
        int const gradeToExecute;


    public:
        Form(std::string const& name, int gradeToSign, int gradeToExecute);
        Form(Form const& src);
        Form& operator=(Form const& src);
        ~Form();

        void beSigned(Bureaucrat const& b);
        bool isSigned() const;
        std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        class GradeTooHighException : public std::exception
        {
            const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            const char* what() const throw();
        };

};

std::ostream& operator<<(std::ostream& out, Form const& f);

#endif