#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : oldestContactIndex(0), totalContacts(0)
{
}

PhoneBook::~PhoneBook()
{
}

void get_input_value(std::string &input, std::string msg, bool &out)
{
    do
        {
            std::getline(std::cin, input);
            if (std::cin.eof())
            {
                std::cin.clear();
                out = true;
                break;
            }
            if (input.empty())
            {
                std::cout << "This field cannot be empty. Please enter a value." << std::endl;
                std::cout << msg;
            }
        } while (input.empty());
}

void PhoneBook::addContact(bool &out)
{

    if (totalContacts < 8)
    {
        Contact newContact;
        std::string input;




        std::cout << "Enter first name: ";
        get_input_value(input, "Enter first name: ", out);
        newContact.setFirstName(input);
        if (out == true)
        {
            return;
        }

        std::cout << "Enter last name: ";
        get_input_value(input, "Enter last name: ", out);
        newContact.setLastName(input);
        if (out == true)
        {
            return;
        }


        std::cout << "Enter nick name: ";
        get_input_value(input, "Enter nick name: ", out);
        newContact.setNickname(input);
        if (out == true)
        {
            return;
        }

        std::cout << "Enter phone number: ";
        get_input_value(input, "Enter phone number: ", out);
        newContact.setPhoneNumber(input);
        if (out == true)
        {
            return;
        }

        std::cout << "Enter darkest secret: ";
        get_input_value(input, "Enter darkest secret: ", out);
        newContact.setDarkestSecret(input);
        if (out == true)
        {
            return;
        }

        contacts[totalContacts] = newContact;

        totalContacts++;
    }
    else
    {
        Contact newContact;
        std::string input;
        
        std::cout << "Enter first name: ";
        get_input_value(input, "Enter first name: ", out);
        newContact.setFirstName(input);
        if (out == true)
        {
            return;
        }

        std::cout << "Enter last name: ";
        get_input_value(input, "Enter last name: ", out);
        newContact.setLastName(input);
        if (out == true)
        {
            return;
        }


        std::cout << "Enter nick name: ";
        get_input_value(input, "Enter nick name: ", out);
        newContact.setNickname(input);
        if (out == true)
        {
            return;
        }

        std::cout << "Enter phone number: ";
        get_input_value(input, "Enter phone number: ", out);
        newContact.setPhoneNumber(input);
        if (out == true)
        {
            return;
        }

        std::cout << "Enter darkest secret: ";
        get_input_value(input, "Enter darkest secret: ", out);
        newContact.setDarkestSecret(input);
        if (out == true)
        {
            return;
        }

        contacts[oldestContactIndex] = newContact;
        oldestContactIndex = (oldestContactIndex + 1) % 8;


    }
}


void PhoneBook::searchContacts() const 
{
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|   Index  |First Name|Last Name | Nickname |" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for (int i = 0; i < totalContacts; i++)
    {
        std::cout << "|" << std::setw(10) << i + 1 << "|";
        std::cout << std::setw(10);
        if (contacts[i].getFirstName().length() > 10)
            std::cout << contacts[i].getFirstName().substr(0, 9) + ".";
        else
            std::cout << contacts[i].getFirstName();
        std::cout << "|";
        std::cout << std::setw(10);
        if (contacts[i].getLastName().length() > 10)
            std::cout << contacts[i].getLastName().substr(0, 9) + ".";
        else
            std::cout << contacts[i].getLastName();
        std::cout << "|";
        std::cout << std::setw(10);
        if (contacts[i].getNickname().length() > 10)
            std::cout << contacts[i].getNickname().substr(0, 9) + ".";
        else
            std::cout << contacts[i].getNickname();
        std::cout << "|" << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl;

    int index;

    std::cout << "Enter the index: ";
    std::cin >> index;
    std::cin.ignore();


    if (index >= 1 && index <= this->totalContacts)
    {
        std::cout << "First Name: " << contacts[index - 1].getFirstName() << std::endl;
        std::cout << "Last Name: " << contacts[index - 1].getLastName() << std::endl;
        std::cout << "Nickname: " << contacts[index - 1].getNickname() << std::endl;
        std::cout << "Phone number: " << contacts[index - 1].getPhoneNumber() << std::endl;
        std::cout << "Darkest secret: " << contacts[index - 1].getDarkestSecret() << std::endl;

    }
    else
    {
        std::cout << "Invalid index" << std::endl;
    }

}