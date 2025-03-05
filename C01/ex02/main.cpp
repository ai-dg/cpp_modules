#include <iostream>
#include <string>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string* stringPTR = &string;
    std::string& stringREF = string;

    std::cout << std::endl << "String memory address: " << std::endl << std::endl;

    std::cout << "String memory address: " << &string << std::endl;
    std::cout << "StringPTR held memory address: " << stringPTR << std::endl;
    std::cout << "StringRED held hememory address: " << &stringREF << std::endl << std::endl;


    std::cout << "String value: " << std::endl;
    
    std::cout << std::endl;
    std::cout << "String value: " << string << std::endl;
    std::cout << "StringPTR held value: " << *stringPTR << std::endl;
    std::cout << "StringREF held value: " << stringREF << std::endl;




    return (0);



}