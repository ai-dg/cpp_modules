#include "MutantStack.hpp"
#include <list>
#include <iostream>

int main()
{
    MutantStack<int> mstack;
    std::list<int> list_test;

    list_test.push_back(5);
    list_test.push_back(17);

    mstack.push(5);
    mstack.push(17);

        std::cout << "*************** List *********" << std::endl;
    std::cout << list_test.back() << std::endl;
    list_test.pop_back();
    std::cout << "List size after pop: " << list_test.size() << std::endl;

        std::cout << "*************** Mutant Stack *********" << std::endl;
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "MutantStack size after pop: " << mstack.size() << std::endl;

    list_test.push_back(3);
    list_test.push_back(5);
    list_test.push_back(737);
    list_test.push_back(0);

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "*************** List *********" << std::endl;
    std::list<int>::iterator it_list = list_test.begin();
    std::list<int>::iterator ite_list = list_test.end();
    ++it_list;
    --it_list;
    while (it_list != ite_list)
    {
        std::cout << *it_list << std::endl;
        ++it_list;
    }

    std::cout << "*************** Mutant Stack *********" << std::endl;
    MutantStack<int>::iterator it_stack = mstack.begin();
    MutantStack<int>::iterator ite_stack = mstack.end();
    ++it_stack;
    --it_stack;
    while (it_stack != ite_stack)
    {
        std::cout << *it_stack << std::endl;
        ++it_stack;
    }
    std::stack<int> s(mstack);
    return 0;
}
