#include <iostream>
#include "Array.hpp"
#include <ctime>
#include <cstdlib>

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}


// void printArray(Array<int> const& array) 
// {
//     for (unsigned int i = 0; i < array.size(); i++) 
//     {
//         std::cout << array[i] << " ";
//     }
//     std::cout << std::endl;
// }

// int main(int, char**)
// {
//     srand(time(NULL));

//     std::cout << "--------------------Test #1----------------------" << std::endl;

//     Array<int> numbers(10);
//     int* mirror = new int[10];
    
//     for (int i = 0; i < 10; i++) {
//         const int value =  rand() % 100;
//         numbers[i] = value;
//         mirror[i] = value;
//     }
    
//     std::cout << std::endl << "--------------Mirror Array-------------------------------" << std::endl;
    
//     for (int i = 0; i < 10; i++)
//     {
//         if (mirror[i] != numbers[i]) 
//         {
//             std::cerr << "Error: Values are not the same!" << std::endl;
//             delete[] mirror;
//             return 1;
//         }
//         std::cout << mirror[i] << " ";
//     }
//     std::cout << std::endl;

//     std::cout << std::endl << "-------------Numbers Array----------" << std::endl;
//     printArray(numbers);
//     std::cout << std::endl << "Values are identical." << std::endl;

//     std::cout << std::endl << "--------------------Test #2----------------------" << std::endl;

//     Array<int> copy = numbers;
//     Array<int> copy2(numbers);
//     Array<int> assignedArray;
//     assignedArray = numbers;

//     std::cout << std::endl << "---------------Copy Array---------------" << std::endl;
//     printArray(copy);
//     std::cout << std::endl << "---------------Copy2 Array---------------" << std::endl;
//     printArray(copy2);
//     std::cout << std::endl << "---------------Original Array------------" << std::endl;
//     printArray(assignedArray);

//     std::cout << std::endl << "--------------------Test #3----------------------" << std::endl;
//     numbers[0] = 9999;
//     if (copy[0] != numbers[0]) 
//     {
//         std::cout << "The 'numbers' and 'copy' arrays are independent." << std::endl;
//         std::cout << "Copy value: " << copy[0] << std::endl;
//         std::cout << "Number value: " << numbers[0] << std::endl;
//     } 
//     else 
//     {
//         std::cerr << "Error: 'numbers' and 'copy' arrays share data!" << std::endl;
//     }

//     std::cout << std::endl << "--------------------Test #4----------------------" << std::endl;

//     try 
//     {
//         numbers[-2] = 0;
//     }
//     catch(std::exception& e) 
//     {
//         std::cerr << "Caught exception for index -2: " << e.what() << std::endl;
//     }
//     try
//     {
//         numbers[10] = 0;
//     }
//     catch(std::exception& e) 
//     {
//         std::cerr << "Caught exception for index " << 10 << ": " << e.what() << std::endl;
//     }

//     std::cout << std::endl << "--------------------Test #5----------------------" << std::endl;
//     for (int i = 0; i < 10; i++) 
//     {
//         numbers[i] = rand() % 100;
//     }
        
//     std::cout << "----------------------Modified Array------------------" << std::endl;
//     printArray(numbers);

//     delete[] mirror;

//     return 0;
// }
