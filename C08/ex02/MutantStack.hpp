#pragma once
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    private:

    public:
        typedef typename std::stack<T>::container_type::iterator iterator;

        MutantStack();
        MutantStack(MutantStack const& src);
        MutantStack& operator=(MutantStack const& src);
        ~MutantStack();

        iterator begin();
        iterator end();

};

#include "MutantStack.tpp"