#ifndef INTERN_HPP
#define INTERN_HPP
#include <string>
#include "AForm.hpp" 


class Intern
{
    private:
        AForm* makeShrubberyCreationForm(std::string const& target) const;
        AForm* makeRobotomyRequestForm(std::string const& target) const;
        AForm* makePresidentialPardonForm(std::string const& target) const;

    public:
        Intern();
        Intern(Intern const& src);
        Intern& operator=(Intern const& src);
        ~Intern();

        AForm* makeForm(std::string const& formName, std::string const& target) const;
};


#endif