#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
    public:
        Contact();
        ~Contact();
        
        /**
         * @brief Setters
         * */    
        void setFirstName(const std::string &firstName);
        void setLastName(const std::string &lastName);
        void setNickname(const std::string &nickName);
        void setPhoneNumber(const std::string &phoneNumber);
        void setDarkestSecret(const std::string &darkestSecret);

        /**
         * @brief Getters
        */
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const; 

    /**
     * @brief Variables
    */
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
};

#endif