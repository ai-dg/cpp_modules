#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <stdexcept>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    protected:
        void checkExecution(Bureaucrat const& executor) const;

    private:
        std::string const name;
        bool _isSigned;
        int const gradeToSign;
        int const gradeToExecute;
        void checkGrade() const;


    public:
        AForm(std::string const& name, int gradeToSign, int gradeToExecute);
        AForm(AForm const& src);
        AForm& operator=(AForm const& src);
        virtual ~AForm();

        void beSigned(Bureaucrat const& b);
        virtual void execute(Bureaucrat const& executor) const = 0;
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
        
        class FormNotSignedException : public std::exception
        {
            const char* what() const throw();
        };
        

};

std::ostream& operator<<(std::ostream& out, AForm const& f);

#endif