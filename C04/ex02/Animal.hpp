#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal
{
    protected:
        std::string type;

    public:
        Animal();
        Animal(Animal const& src);
        Animal& operator=(Animal const &src);
        virtual ~Animal();

    std::string getType() const;
    virtual void makeSound() const = 0;

};


#endif