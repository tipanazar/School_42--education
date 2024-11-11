#include "Zombie.hpp"
#include <cstdlib>
#include <sstream>

Zombie *zombieHorde(int N, std::string name)
{
    if (N < 0)
    {
        std::cout << "Invalid N" << std::endl;
        exit(1); //! cleans mem alloc
        // abort(); //! does not clean mem alloc
    }
    Zombie *zombies = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        std::stringstream index;
        index << i;
        zombies[i].setName(name + " - " + index.str());
    }
    return zombies;
}