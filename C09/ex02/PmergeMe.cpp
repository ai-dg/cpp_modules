#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>

PmergeMe::PmergeMe() 
{
    // std::cout << "PmergeMe class object has been created" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const& src)
    : numbers_vector(src.numbers_vector), numbers_deque(src.numbers_deque) 
{
    // std::cout << "PmergeMe class object has been copied" << std::endl;
}

PmergeMe& PmergeMe::operator=(PmergeMe const& src)
{
    if (this != &src)
    {
        numbers_vector = src.numbers_vector;
        numbers_deque = src.numbers_deque;
    }
    // std::cout << "PmergeMe class object has been assigned" << std::endl;
    return *this;
}

PmergeMe::~PmergeMe() 
{
    // std::cout << "PmergeMe class object has been destroyed" << std::endl;
}

bool PmergeMe::checkValues(char** av) 
{
    for (int i = 1; av[i]; ++i)
    {
        for (size_t j = 0; av[i][j]; ++j)
        {
            if (!std::isdigit(av[i][j]))
            {
                return false;
            }
            if (av[i][j] == '-')
            {
                return false;
            }
        }
    }
    return true;
}

void PmergeMe::addValuesToContainers(char** av) 
{
    for (int i = 1; av[i]; ++i)
    {
        numbers_vector.push_back(std::atoi(av[i]));
        numbers_deque.push_back(std::atoi(av[i]));
    }
}

void PmergeMe::takePairsVector(std::vector<int>& vec, std::vector<std::pair<int, int> >& pairs, std::vector<int>& mainChain)
{
    for (size_t i = 0; i < vec.size(); i += 2)
    {
        if (i + 1 < vec.size())
        {
            if (vec[i] >= vec[i + 1])
            {
                pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
            }
            else
            {
                pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
            }
        }
        else
        {
            mainChain.push_back(vec[i]);
        }
    }
}

void PmergeMe::putElementsInSmallElementsVector(std::vector<std::pair<int, int> >& pairs, std::vector<int>& smallElements)
{
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].first < pairs[i].second)
        {
            smallElements.push_back(pairs[i].first);
        }
        else if (pairs[i].first > pairs[i].second)
        {
            smallElements.push_back(pairs[i].second);
        }
        else
        {
            // smallElements.push_back(pairs[i].first);
            smallElements.push_back(pairs[i].second);
        }
    }
}

void PmergeMe::putElementsInMainChainVector(std::vector<std::pair<int, int> >& pairs, std::vector<int>& mainChain)
{
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].first > pairs[i].second)
        {
            mainChain.push_back(pairs[i].first);
        }
        else if (pairs[i].first < pairs[i].second)
        {
            mainChain.push_back(pairs[i].second);
        }
        else
        {
            mainChain.push_back(pairs[i].first);
            // mainChain.push_back(pairs[i].second);
        }
    }
}

void PmergeMe::insertionSortInMainVector(std::vector<int>& mainChain)
{
    for (size_t i = 1; i < mainChain.size(); ++i)
    {
        int key = mainChain[i];
        size_t j = i;
        while (j > 0 && mainChain[j - 1] > key)
        {
            mainChain[j] = mainChain[j - 1];
            --j;
        }
        mainChain[j] = key;
    }
}

void PmergeMe::insertSmallElementsInMainChainVector(const std::vector<int>& smallElements, std::vector<int>& mainChain)
{
    for (size_t i = 0; i < smallElements.size(); ++i)
    {
        int element = smallElements[i];
        
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), element);
        
        mainChain.insert(pos, element);
    }
}

void PmergeMe::mergeInsertionSortVector(std::vector<int>& vec) 
{
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> mainChain;
    std::vector<int> smallElements;

    takePairsVector(vec, pairs, mainChain);
    putElementsInSmallElementsVector(pairs, smallElements);
    putElementsInMainChainVector(pairs, mainChain);
    insertionSortInMainVector(mainChain);
    insertSmallElementsInMainChainVector(smallElements, mainChain);

    // std::cout << "Pairs: ";
    // for (size_t i = 0; i < pairs.size(); ++i)
    //     std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";
    
    // std::cout << std::endl;

    // std::cout << "Main chain: ";
    // for (size_t i = 0; i < mainChain.size(); ++i)
    //     std::cout << mainChain[i] << " ";
    // std::cout << std::endl;

    // std::cout << "Small elements: ";
    // for (size_t i = 0; i < smallElements.size(); ++i)
    //     std::cout << smallElements[i] << " ";
    // std::cout << std::endl;
    vec = mainChain;
}

void PmergeMe::takePairsDeque(std::deque<int>& deq, std::deque<std::pair<int, int> >& pairs, std::deque<int>& mainChain) 
{
    for (size_t i = 0; i < deq.size(); i += 2) 
    {
        if (i + 1 < deq.size()) 
        {
            if (deq[i] >= deq[i + 1]) 
            {
                pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
            } 
            else 
            {
                pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
            }
        } 
        else 
        {
            mainChain.push_back(deq[i]);
        }
    }
}

void PmergeMe::putElementsInSmallElementsDeque(std::deque<std::pair<int, int> >& pairs, std::deque<int>& smallElements) 
{

    for (size_t i = 0; i < pairs.size(); ++i) 
    {
        if (pairs[i].first < pairs[i].second)
        {
            smallElements.push_back(pairs[i].first);
        }
        else if (pairs[i].first > pairs[i].second)
        {
            smallElements.push_back(pairs[i].second);
        }
        else
        {
            // smallElements.push_back(pairs[i].first);
            smallElements.push_back(pairs[i].second);
        }
    }
}

void PmergeMe::putElementsInMainChainDeque(std::deque<std::pair<int, int> >& pairs, std::deque<int>& mainChain) 
{
    for (size_t i = 0; i < pairs.size(); ++i) 
    {
        if (pairs[i].first > pairs[i].second)
        {
            mainChain.push_back(pairs[i].first);
        }
        else if (pairs[i].first < pairs[i].second)
        {
            mainChain.push_back(pairs[i].second);
        }
        else
        {
            mainChain.push_back(pairs[i].first);
            // mainChain.push_back(pairs[i].second);
        }
    }
}

void PmergeMe::insertionSortInMainDeque(std::deque<int>& mainChain) 
{
    for (size_t i = 1; i < mainChain.size(); ++i) 
    {
        int key = mainChain[i];
        size_t j = i;
        while (j > 0 && mainChain[j - 1] > key) 
        {
            mainChain[j] = mainChain[j - 1];
            --j;
        }
        mainChain[j] = key;
    }
}

void PmergeMe::insertSmallElementsInMainChainDeque(const std::deque<int>& smallElements, std::deque<int>& mainChain) 
{
    for (size_t i = 0; i < smallElements.size(); ++i)
    {
        int element = smallElements[i];
        
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), element);
        
        mainChain.insert(pos, element);
    }
}

void PmergeMe::mergeInsertionSortDeque(std::deque<int>& deq) 
{
    std::deque<std::pair<int, int> > pairs;
    std::deque<int> mainChain;
    std::deque<int> smallElements;

    takePairsDeque(deq, pairs, mainChain);
    putElementsInSmallElementsDeque(pairs, smallElements);
    putElementsInMainChainDeque(pairs, mainChain);
    insertionSortInMainDeque(mainChain);
    insertSmallElementsInMainChainDeque(smallElements, mainChain);

    deq = mainChain;
}

void PmergeMe::mergeInsertSort()
{
    const int repetitions = 100;

    std::cout << "Before: ";
    for (size_t i = 0; i < numbers_vector.size(); ++i)
        std::cout << numbers_vector[i] << " ";
    std::cout << std::endl;

    /**
     * @brief Measure the time to process a range of elements with std::vector and std::deque
     */
    clock_t start_vector = clock();
    for (int i = 0; i < repetitions; ++i) 
    {
        std::vector<int> numbers_vector_copy = numbers_vector;
        mergeInsertionSortVector(numbers_vector_copy);
    }
    clock_t end_vector = clock();
    double time_vector = (double)(end_vector - start_vector) / CLOCKS_PER_SEC * 1000000 / repetitions;
    
    
    clock_t start_deque = clock();
    for (int i = 0; i < repetitions; ++i) 
    {
        std::deque<int> numbers_deque_copy = numbers_deque;
        mergeInsertionSortDeque(numbers_deque_copy);
    }
    clock_t end_deque = clock();
    double time_deque = (double)(end_deque - start_deque) / CLOCKS_PER_SEC * 1000000 / repetitions;
    
    
    /**
     * @brief Measure the time to process a range of elements with std::vector and std::deque using the default sort function
     */
    // clock_t start_vector_default = clock();
    // for (int i = 0; i < repetitions; ++i) 
    // {
    //     std::vector<int> numbers_vector_copy = numbers_vector;
    //     std::sort(numbers_vector_copy.begin(), numbers_vector_copy.end());
    // }
    // clock_t end_vector_default = clock();
    // double time_vector_default = (double)(end_vector_default - start_vector_default) / CLOCKS_PER_SEC * 1000000 / repetitions;
    
    
    // clock_t start_deque_default = clock();
    // for (int i = 0; i < repetitions; ++i) 
    // {
    //     std::deque<int> numbers_deque_copy = numbers_deque;
    //     std::sort(numbers_deque_copy.begin(), numbers_deque_copy.end());
    // }
    // clock_t end_deque_default = clock();
    // double time_deque_default = (double)(end_deque_default - start_deque_default) / CLOCKS_PER_SEC * 1000000 / repetitions;
    


    mergeInsertionSortVector(numbers_vector);
    mergeInsertionSortDeque(numbers_deque);
    
    for (size_t i = 0; i < numbers_vector.size(); ++i)
    {
        if (numbers_deque[i] != numbers_vector[i])
        {
            std::cerr << "Error: the two containers are not equal" << std::endl;
            return;
        }
    }
    // std::cout << "After with vector: ";
    // for (size_t i = 0; i < numbers_vector.size(); ++i)
    //     std::cout << numbers_vector[i] << " ";
    // std::cout << std::endl;

    // std::cout << "After with deque: ";
    // for (size_t i = 0; i < numbers_deque.size(); ++i)
    //     std::cout << numbers_deque[i] << " ";
    // std::cout << std::endl;

    std::cout << "After:  ";
    for (size_t i = 0; i < numbers_deque.size(); ++i)
        std::cout << numbers_deque[i] << " ";
    std::cout << std::endl;

    if (!is_sorted(numbers_vector))
    {
        std::cerr << "Error: the vector container is not sorted" << std::endl;
    }
    if (!is_sorted(numbers_deque))
    {
        std::cerr << "Error: the deque container is not sorted" << std::endl;
    }

    /**
     * @brief Display the time to process a range of elements with std::vector
     */
    std::cout << "Time to process a range of " << numbers_vector.size() << " elements with std::vector: " 
              << std::fixed << std::setprecision(5) << time_vector << " us" << std::endl;
    // std::cout << "Time to process a range of " << numbers_vector.size() << " elements with default sort std::vector: " 
    //           << std::fixed << std::setprecision(5) << time_vector_default << " us" << std::endl;
    /**
     * @brief Display the time to process a range of elements with std::deque
     */
    std::cout << "Time to process a range of " << numbers_deque.size() << " elements with std::deque: " 
              << std::fixed << std::setprecision(5) << time_deque << " us" << std::endl;
    // std::cout << "Time to process a range of " << numbers_deque.size() << " elements with default sort std::deque: " 
    //           << std::fixed << std::setprecision(5) << time_deque_default << " us" << std::endl;
}
