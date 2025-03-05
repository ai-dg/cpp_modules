#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook();
        ~PhoneBook();

        void addContact(bool &out);
        void searchContacts() const;

    private:
        Contact contacts[8];
        int oldestContactIndex;
        int totalContacts;
};

#endif
