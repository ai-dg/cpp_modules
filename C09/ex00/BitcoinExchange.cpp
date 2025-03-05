#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

BitcoinExchange::BitcoinExchange()
{
    // std::cout << "BitcoinExchange class object has been created" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& src) : data_csv(src.data_csv), data_input(src.data_input), data_result(src.data_result)
{
    std::cout << "BitcoinExchange class object has been copied" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& src)
{
    if (this != &src)
    {
        data_csv.clear();
        data_input.clear();
        data_result.clear();
        data_csv = src.data_csv;
        data_input = src.data_input;
        data_result = src.data_result;
    }
    std::cout << "BitcoinExchange class object has been assigned" << std::endl;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    // std::cout << "BitcoinExchange class object has been destroyed" << std::endl;
}

double BitcoinExchange::stringToDouble(std::string const& str)
{
    double result;
    std::stringstream ss(str);
    if (!(ss >> result)) 
    {
        return INVALID_VALUE;
    }
    return result;   
}

float BitcoinExchange::stringToFloat(std::string const& str)
{
    float result;
    std::stringstream ss(str);
    if (!(ss >> result))
    {
        return INVALID_VALUE;
    }
    return result;
}

bool BitcoinExchange::isValidDate(std::string const& date) const 
{
    // std::cout << "Size: " << date.size() << std::endl;
    // std::cout << "Date[4]: " << date[4] << std::endl;
    // std::cout << "Date[7]: " << date[7] << std::endl;

    return date.size() == 10 && date[4] == '-' && date[7] == '-';
}

bool BitcoinExchange::isNumeric(std::string const& str) const
{
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) 
    {
        if (*it == '.' || *it == '-')
        {
            continue;
        }
        if (!std::isdigit(*it)) 
        {
            return false;
        }
    }
    return true;
}

void BitcoinExchange::loadDataCsv(std::string const& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open csv file" << std::endl;
        return;
    }

    std::string line;
    if (std::getline(file, line))
    {
        if (line.empty())
        {
            std::cerr << "Error: empty csv data file" << std::endl;
            return;
        }
        if (line != "date,exchange_rate")
        {
            std::cerr << "Error: invalid header csv data file" << std::endl;
            return;
        }
    }
    while (std::getline(file, line))
    {
        int date_pos = line.find(",");
        std::string date = line.substr(0, date_pos);
        std::string price = line.substr(date_pos + 1);
        if (price == "exchange_rate")
        {
            continue;
        }
        double price_double = stringToDouble(price);
        data_csv.push_back(std::make_pair(date, price_double));

    }
    data_csv.sort();
}

void BitcoinExchange::displayData()
{
    for (std::list<std::pair<std::string, double> >::const_iterator it = data_csv.begin(); it != data_csv.end(); ++it)
    {
        std::cout << it->first << " : " << it->second << std::endl;
    }
}

void BitcoinExchange::loadInput(char* filename) 
{
    std::ifstream file(filename);
    if (!file.is_open()) 
    {
        std::cerr << "Error: could not open input file" << std::endl;
        return;
    }

    std::string line;
    if (std::getline(file, line))
    {
        if (line.empty())
        {
            std::cerr << "Error: empty input file" << std::endl;
            return;
        }

        if (line != "date | value")
        {
            std::cerr << "Error: invalid header input file" << std::endl;
            return;
        }
    }
    int index = 0;
    while (std::getline(file, line)) 
    {
        // std::cout << "Line: " << line << std::endl;

        size_t date_post = line.find("|");
        size_t count = std::count(line.begin(), line.end(), '|');
        if (date_post == std::string::npos || count != 1)
        {
            data_input.push_back(std::make_pair(line, INVALID_LINE));
            continue;
        }
        std::string date = line.substr(0, date_post);
        date.erase(date.find_last_not_of(" \t") + 1);
        // std::cout << "Date: " << date << std::endl;
        if (!isValidDate(date))
        {
            data_input.push_back(std::make_pair(date, INVALID_DATE));
            continue;
        }

        std::string amount = line.substr(date_post + 1);
        amount.erase(0, amount.find_first_not_of(" \t"));
        if (!isNumeric(amount))
        {
            data_input.push_back(std::make_pair(amount, INVALID_AMOUNT_NUMERIC));
            continue;
        }
        double amount_double = stringToDouble(amount);
        // std::cout << "Amount: " << amount_double << std::endl;
        if (amount_double == INVALID_VALUE)
        {
            data_input.push_back(std::make_pair(date, INVALID_VALUE));
            continue;
        }
        if (amount_double < 0)
        {
            data_input.push_back(std::pair<std::string, float>(date, INVALID_AMOUNT));
            continue;
        }
        if (amount_double > 1000)
        {
            data_input.push_back(std::pair<std::string, float>(date, INVALID_PRICE));
            continue;
        }

        data_input.push_back(std::make_pair(date, amount_double));
        index++;
    }
    // std::cout << "Number of lines: " << index << std::endl;
    loadToResult();
}

void BitcoinExchange::displayInput()
{
    std::cout << "Displaying input data" << std::endl;
    std::list<std::pair<std::string, double> >::const_iterator it = data_input.begin();
    while (it != data_input.end())
    {
        std::cout << it->first << " : " << it->second << std::endl;
        it++;
    }
}
void BitcoinExchange::loadToResult()
{
    if (data_csv.empty() || data_input.empty())
    {
        std::cerr << "Error: no data to process" << std::endl;
        return;
    }
    std::list<std::pair<std::string, double> >::const_iterator it = data_input.begin();
    while (it != data_input.end())
    {
        if (it->second < 0)
        {
            data_result.push_back(std::make_pair(it->first, it->second));   
            ++it;
            continue;
        }

        std::string closest_date;
        double exchange_rate = 0.0;
        bool found = false;

        for (std::list<std::pair<std::string, double> >::const_iterator it_csv = data_csv.begin(); it_csv != data_csv.end(); ++it_csv)
        {
            if (it_csv->first <= it->first)
            {
                closest_date = it_csv->first;
                exchange_rate = it_csv->second;
                found = true;
            }
            else
            {
                break;
            }
        }

        if (found)
        {
            double result_value = it->second * exchange_rate;
            data_result.push_back(std::make_pair(it->first, result_value));
        }
        else
        {
            data_result.push_back(std::make_pair(it->first, INVALID_DATE_EXIST));
        }

        ++it;
    }
}

void BitcoinExchange::displayResult() 
{
    std::cout << "Displaying result data" << std::endl;
    std::list<std::pair<std::string, double> >::const_iterator it = data_result.begin();
    while (it != data_result.end())
    {
        std::cout << it->first << " : " << it->second << std::endl;
        it++;
    }

}

bool BitcoinExchange::check_if_invalid(std::list<std::pair<std::string, double> >::const_iterator const& it) const
{
    if (it->second == INVALID_LINE)
    {
        std::cerr << "Error: bad input => " << it->first << std::endl;
        return true;
    }
    else if (it->second == INVALID_PRICE)
    {
        std::cerr << "Error: too large a number" << std::endl;
        return true;
    }
    else if (it->second == INVALID_DATE)
    {
        std::cerr << "Error: invalid date format" << std::endl;
        return true;
    }
    else if (it->second == INVALID_AMOUNT)
    {
        std::cerr << "Error: not a positive number" << std::endl;
        return true;
    }
    else if (it->second == INVALID_VALUE)
    {
        std::cerr << "Error: amount is not a valid number" << std::endl;
        return true;
    }
    else if (it->second == INVALID_DATE_EXIST)
    {
        std::cerr << "Error: date does not exist in the csv file" << std::endl;
        return true;
    }
    else if (it->second == INVALID_AMOUNT_NUMERIC)
    {
        std::cerr << "Error: amount is not a valid number => " << it->first << std::endl;
        return true;
    }
    return false;
}


void BitcoinExchange::displayFinalResult()
{
    if (data_input.empty() || data_result.empty())
    {
        std::cerr << "Error: no input data" << std::endl;
        return;
    }
    std::list<std::pair<std::string, double> >::const_iterator it_input = data_input.begin();
    std::list<std::pair<std::string, double> >::const_iterator it_result = data_result.begin();

    while (it_input != data_input.end() && it_result != data_result.end())
    {
        if (check_if_invalid(it_result))
        {

            ++it_input;
            ++it_result;
            continue;
        }
        std::cout << it_input->first << " => " << it_input->second << " = " << it_result->second << std::endl;
        ++it_input;
        ++it_result;
    }
}
