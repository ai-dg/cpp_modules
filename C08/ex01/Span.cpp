#include "Span.hpp"
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>

Span::Span(unsigned int size): size(size)
{
    std::cout << "Span class object has been created" << std::endl;
}

Span::Span(Span const& src): size(src.size), numbers(src.numbers)
{
    std::cout << "Span class object has been copied" << std::endl;
}

Span& Span::operator=(Span const& src)
{
    if (this != &src)
    {
        numbers.clear();
        size = src.size;
        numbers = src.numbers;
    }
    std::cout << "Span class object has been assigned" << std::endl;
    return *this;
}

Span::~Span()
{
    std::cout << "Span class object has been destroyed" << std::endl;
}


void Span::addNumber(int number)
{
    if (numbers.size() < size)
    {
        numbers.push_back(number);
    }
    else
    {
        throw Span::SpanEnoughException();
    }
}

int Span::shortestSpan() const
{
    if (numbers.size() < 2)
        throw Span::SpanNotEnoughException();

    std::vector<int> numbers_sorted = numbers;
    std::sort(numbers_sorted.begin(), numbers_sorted.end());

    int span_min = numbers_sorted[1] - numbers_sorted[0];
    for (unsigned int i = 0; i < numbers_sorted.size() - 1; i++)
    {
        int span = numbers_sorted[i + 1] - numbers_sorted[i];
        if (span < span_min)
        {
            span_min = span;
        }
    }
    return span_min;
}

int Span::longestSpan() const
{
    if (numbers.size() < 2)
        throw Span::SpanNotEnoughException();

    std::vector<int> numbers_sorted(this->numbers);
    std::sort(numbers_sorted.begin(), numbers_sorted.end());

    int span = numbers_sorted[numbers_sorted.size() - 1] - numbers_sorted[0];
    
    return span;
}

void Span::printNumbers() const
{
    std::cout << "Numbers: ";
    for (unsigned int i = 0; i < numbers.size(); i++)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}


char const* Span::SpanEnoughException::what() const throw()
{
    return "Span is full, it cannot add more numbers";
}

char const* Span::SpanNotEnoughException::what() const throw()
{
    return "Not enough numbers to find a span";
}