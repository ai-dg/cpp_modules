#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const& src);
        ScalarConverter& operator=(ScalarConverter const& src);
        ~ScalarConverter();

        static void convertToChar(double value);
        static void convertToInt(double value);
        static void convertToFloat(double value);
        static void convertToDouble(double value);


    public:
        static void convert(std::string const& value);

};

#endif