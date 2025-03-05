#ifndef BRAIN_CPP
# define BRAIN_CPP

#include <string>

class Brain
{
    private:
        std::string ideas[100];
    
    public:
        Brain();
        Brain(Brain const &src);
        Brain& operator=(Brain const& src);
        ~Brain();

        std::string getIdea(int index) const;
        void setIdea(int index, std::string idea);


};

#endif