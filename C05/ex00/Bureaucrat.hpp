#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>
#include <iostream>

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

        std::string const getName(void) const;
        int getGrade(void) const;
        void setGrade(int const grade);

        class GradeTooHighException : public std::exception
        {
            const char*  what() const throw();
            
        };

        class GradeTooLowException: public std::exception
        {
            const char* what() const throw();
        };

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);



#endif