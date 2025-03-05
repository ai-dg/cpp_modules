#include "ScalarConverter.hpp"
#include <iostream>
#include <cmath>
#include <cerrno>
#include <limits>
#include <cstdlib>

/**
 * @brief Private:
 */
ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter has been created" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const& src)
{
    (void)src;
    std::cout << "ScalarConverter has been copied" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& src)
{
    (void)src;
    std::cout << "ScalarConverter has been assigned" << std::endl;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter has been destroyed" << std::endl;
}

void ScalarConverter::convertToChar(double value)
{
    if (value < 0 || value > 255 || std::isnan(value) || std::isinf(value))
    {
        std::cout << "char: impossible" << std::endl;
    }
    else if (!std::isprint(static_cast<int>(value)))
    {
        std::cout << "char: Non displayable" << std::endl;
    }
    else
    {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl; 
    }
}

void ScalarConverter::convertToInt(double value)
{
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || std::isinf(value) || std::isnan(value))
    {
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
}

void ScalarConverter::convertToFloat(double value)
{
    std::cout << "float: " << static_cast<float>(value);
    if (value == static_cast<int>(value))
    {
        std::cout << ".0f" << std::endl;
    }
    else
    {
        std::cout << "f" << std::endl;
    }

}

void ScalarConverter::convertToDouble(double value)
{
    std::cout << "double: " << value;
    if (value == static_cast<int>(value))
    {
        std::cout << ".0" << std::endl;
    }
    else
    {
        std::cout << std::endl;
    }

}

/**
 * @brief Public:
 */
void ScalarConverter::convert(std::string const& value)
{
    errno = 0;
    double number = std::strtod(value.c_str(), NULL);
    if (errno == ERANGE)
    {
        std::cerr << "Error: Out of range" << std::endl;
        return;
    }

    if (value.length() == 1 && !std::isdigit(value[0]))
    {
        number = static_cast<double>(value[0]);
    }
    
    convertToChar(number);
    convertToInt(number);
    convertToFloat(number);
    convertToDouble(number);
}