#pragma once
#include <vector>
#include <iterator>
#include <stdexcept>

class Span
{
    private:
        unsigned int size;
        std::vector<int> numbers;

    public:
        Span(unsigned int size);
        Span(Span const& src);
        Span& operator=(Span const& src);
        ~Span();

        void addNumber(int number);

        template <typename Iterator>
        void addNumbers(Iterator begin, Iterator end)
        {
            if (std::distance(begin, end) + numbers.size() > size) 
            {
                throw Span::SpanEnoughException();
            }
            numbers.insert(numbers.end(), begin, end);
        }

        int shortestSpan() const;
        int longestSpan() const;
        void printNumbers() const;

        class SpanEnoughException : public std::exception
        {
            virtual char const* what() const throw();

        };

        class SpanNotEnoughException : public std::exception
        {
            virtual char const* what() const throw();
        };        

};

