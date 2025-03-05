#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;

    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const& src);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm const& src);
        ~ShrubberyCreationForm();

        void execute(Bureaucrat const& executor) const;


};

#endif