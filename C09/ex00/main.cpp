#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    BitcoinExchange exchange;
    exchange.loadDataCsv("data.csv");
    // exchange.displayData();
    exchange.loadInput(av[1]);
    // exchange.displayInput();
    // exchange.displayResult();
    exchange.displayFinalResult();
    return 0;    
}