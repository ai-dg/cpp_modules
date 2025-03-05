#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Array of Animals ===" << std::endl;
    const Animal* animals[4];

    animals[0] = new Dog();
    animals[1] = new Dog();
    animals[2] = new Cat();
    animals[3] = new Cat();

    std::cout << "=== Making Sounds ===" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        animals[i]->makeSound();
    }

    std::cout << "=== Deleting Animals ===" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        delete animals[i];
    }

    std::cout << "=== Deep Copy Test ===" << std::endl;
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "Chase the cat");

    // Dog copyDog(originalDog);
    Dog copyDog = originalDog;
    std::cout << "Original Dog's first idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Dog's first idea: " << copyDog.getBrain()->getIdea(0) << std::endl;

    copyDog.getBrain()->setIdea(0, "Bark at the mailman");
    std::cout << "Original Dog's first idea after change: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Dog's first idea after change: " << copyDog.getBrain()->getIdea(0) << std::endl;

    return 0;
}
