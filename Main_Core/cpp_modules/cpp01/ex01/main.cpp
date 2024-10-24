#include "Zombie.hpp"

int main(void)
{
    int N = 0;
    Zombie *zombies = zombieHorde(N, "zomb");

    if (zombies)
    {

        for (int i = 0; i < N; i++)
        {
            zombies[i].announce();
        }
        delete[] zombies;
    }
    return 0;
}
