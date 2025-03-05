#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;

    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const& src);
        PresidentialPardonForm& operator=(PresidentialPardonForm const& src);
        ~PresidentialPardonForm();

        void execute(Bureaucrat const& executor) const;

};

#endif