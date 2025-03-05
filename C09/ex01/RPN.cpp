#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <cctype>

RPN::RPN()
{
    // std::cout << "RPN class object has been created" << std::endl;
}

RPN::RPN(RPN const& src) : data(src.data)
{
    // std::cout << "RPN class object has been copied" << std::endl;
}

RPN& RPN::operator=(RPN const& src)
{
    if (this != &src)
    {
        data.empty();
        data = src.data;
    }
    // std::cout << "RPN class object has been assigned" << std::endl;
    return *this;
}

RPN::~RPN()
{
    // std::cout << "RPN class object has been destroyed" << std::endl;
}

int RPN::stringToInt(std::string const& str)
{
    std::stringstream ss(str);
    int num;
    ss >> num;
    return num;
}

std::string RPN::intToString(int num)
{
    std::stringstream ss;
    ss << num;
    std::string str = ss.str();
    return str;
}

bool RPN::applyOperation(char c)
{
    int value2 = stringToInt(data.top());
    data.pop();
    int value1 = stringToInt(data.top());
    data.pop();

    if (c == '+')
        result = value1 + value2;
    else if (c == '-')
        result = value1 - value2;
    else if (c == '*')
        result = value1 * value2;
    else if (c == '/')
    {
        if (value2 == 0) 
        {
            // std::cerr << "Error" << std::endl;
            return false;
        }
        result = value1 / value2;
    }
    return true;
}

void RPN::calculate(std::string operation)
{
    for (size_t i = 0; i < operation.length(); ++i)
    {
        char c = operation[i];
        if (std::isspace(c)) 
            continue;
        if (std::isdigit(c)) 
        {
            int number = c - '0';
            if (number >= 10)
            {
                // std::cerr << "Error" << std::endl;
                return;
            }
            data.push(std::string(1, c));
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') 
        {
            if (data.size() < 2) 
            {
                // std::cerr << "Error" << std::endl;
                return;
            }
            result = 0;
            if (!applyOperation(c))
                return;
            data.push(intToString(result));
        }
        else 
            return;
    }
}

void RPN::displayStack()
{
    std::stack<std::string> tmp = data;
    while (!tmp.empty())
    {
        std::cout << tmp.top() << std::endl;
        tmp.pop();
    }
}

void RPN::displayResult()
{
    if (data.size() == 1)
    {
        std::cout << data.top() << std::endl;
        data.pop();
    }
    else
    {
        std::cerr << "Error" << std::endl;
    }

}
