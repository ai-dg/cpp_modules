#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        std::string const name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string const name, int const grade);
        Bureaucrat(Bureaucrat const& src);
        Bureaucrat& operator=(Bureaucrat const& src);
        ~Bureaucrat();

        void incrementGrade(void);
        void decrementGrade(void);
        void signForm(Form& f);

        std::string const getName(void) const;
        int getGrade(void) const;
        void setGrade(int const grade);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char*  what() const throw();
            
        };

        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);



#endif