#include "Zombie.hpp"


Zombie* newZombie(std::string name);
void randomChump(std::string name);


int main(void)
{
    Zombie* heap = newZombie("heap");
    
    Zombie stack("stack");

    heap->announce();
    stack.announce();
    randomChump("random stack");


    delete(heap);


}