#include "PhoneBook.hpp"
#include <iostream>

int main() 
{
    PhoneBook       PhoneBook;
    std::string     command;

    bool out = false;

    while (true)
    {
        std::cout << "Enter the commmand (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command))
        {
            std::cout << "\nExiting program." << std::endl;
            return 1;
        }

        if (command == "ADD")
        {
            PhoneBook.addContact(out);
            if (out == true)
            {
                std::cout << "\nExiting program." << std::endl;
                return 1;
            }

        }
        else if (command == "SEARCH")
            PhoneBook.searchContacts();
        else if (command == "EXIT")
        {
            std::cout << "Exiting program." << std::endl;
            return 0;
        }
        else if (command[0] == 0)
            continue;
        else
        {
            std::cout << "Unknown command" << std::endl;
            continue;
        }
        
    }

    return 0;
}
