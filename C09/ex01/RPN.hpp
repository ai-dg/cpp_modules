#pragma once
#include <stack>
#include <string>

class RPN
{
    private:
        std::stack<std::string> data;
        int result;
        
    public:
        RPN();
        RPN(RPN const& src);
        RPN& operator=(RPN const& src);
        ~RPN();

        /**
         * @brief Generic functions
         */
        int stringToInt(std::string const& str);
        std::string intToString(int num);

        /**
         * @brief RPN calculator functions
         */
        bool applyOperation(char c);
        void calculate(std::string operation);

        /**
         * @brief Display functions
         */
        void displayStack();
        void displayResult();
};