#include "Zombie.hpp"

int main(void)
{
    int N = -1;
    Zombie *zombies = zombieHorde(-1, "zomb");

    if (zombies)
    {

        for (int i = 0; i < N; i++)
        {
            zombies[i].announce();
        }
        delete[] zombies;
    }

    Zombie *zombies2 = zombieHorde(-1, "zomb");

    if (zombies2)
    {

        for (int i = 0; i < N; i++)
        {
            zombies2[i].announce();
        }
        delete[] zombies2;
    }
    return 0;
}
