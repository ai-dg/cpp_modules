#pragma once
#include <vector>
#include <deque>

class PmergeMe
{
    private:
        std::vector<int> numbers_vector;
        std::deque<int> numbers_deque;



    public:
        PmergeMe();
        PmergeMe(PmergeMe const& src);
        PmergeMe& operator=(PmergeMe const& src);
        ~PmergeMe();

        /**
         * @brief Generic functions
         */ 
        template <typename T>
        bool is_sorted(T const& container)
        {
            for (std::size_t i = 1; i < container.size(); ++i)
            {
                if (container[i] < container[i - 1])
                    return false;
            }
            return true;
        }

        bool checkValues(char** av);
        void addValuesToContainers(char** av);


        /**
         * @brief Merge vector sort functions
         */
        void takePairsVector(std::vector<int>& vec, std::vector<std::pair<int, int> >& pairs, std::vector<int>& mainChain);
        void putElementsInSmallElementsVector(std::vector<std::pair<int, int> >& pairs, std::vector<int>& smallElements);
        void putElementsInMainChainVector(std::vector<std::pair<int, int> >& pairs, std::vector<int>& mainChain);
        void insertionSortInMainVector(std::vector<int>& mainChain);
        void insertSmallElementsInMainChainVector(const std::vector<int>& smallElements, std::vector<int>& mainChain);
        void mergeInsertionSortVector(std::vector<int>& vec);

        /**
         * @brief Merge deque sort functions
         */
        void takePairsDeque(std::deque<int>& deq, std::deque<std::pair<int, int> >& pairs, std::deque<int>& mainChain);
        void putElementsInSmallElementsDeque(std::deque<std::pair<int, int> >& pairs, std::deque<int>& smallElements);
        void putElementsInMainChainDeque(std::deque<std::pair<int, int> >& pairs, std::deque<int>& mainChain);
        void insertionSortInMainDeque(std::deque<int>& mainChain);
        void insertSmallElementsInMainChainDeque(const std::deque<int>& smallElements, std::deque<int>& mainChain);
        void mergeInsertionSortDeque(std::deque<int>& deq);
        
        /**
         * @brief Main function
         */
        void mergeInsertSort();
};

