#pragma once
#include <string>
#include <list>

const double INVALID_LINE = -1.0;
const double INVALID_PRICE = -2.0;
const double INVALID_DATE = -3.0;
const double INVALID_AMOUNT = -4.0;
const double INVALID_VALUE = -5.0;
const double INVALID_DATE_EXIST = -6.0;
const double INVALID_AMOUNT_NUMERIC = -7.0;

class BitcoinExchange
{
    private:
        std::list<std::pair<std::string, double> > data_csv;
        std::list<std::pair<std::string, double> > data_input;
        std::list<std::pair<std::string, double> > data_result;

    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const& src);
        BitcoinExchange& operator=(BitcoinExchange const& src);
        ~BitcoinExchange();

        /**
         * @brief Generic functions
         */
        double stringToDouble(std::string const& str);
        float stringToFloat(std::string const& str);
        bool isValidDate(std::string const& date) const;
        bool isNumeric(std::string const& str) const;
        
        /**
         * @brief Data CSV functions
         */
        void loadDataCsv(std::string const& filename);
        void displayData();

        /**
         * @brief Data input functions
         */
        void loadInput(char* filename);
        void displayInput();

        /**
         * @brief Data result functions
         */
        void loadToResult();
        void displayResult();

        /**
         * @brief Final result functions
         */
        bool check_if_invalid(std::list<std::pair<std::string, double> >::const_iterator const& it) const;
        void displayFinalResult();
};

