#include "Zombie.hpp"

int main()
{
    Zombie *heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;

    randomChump("StackZombie");

    return 0;
}

/**
 * heapZombie is allocated on the heap using newZombie("HeapZombie").
 * This is appropriate if heapZombie needs to persist beyond the function's scope
 * or if you need to manage its lifetime manually.
 *
 * randomChump("StackZombie") suggests that the zombie is created and used
 * within the function's scope, likely on the stack. This is efficient
 * if the zombie's lifetime is limited to the function call.
 */

/*
    Heap allocation when you need more control over the object's lifetime
    or when dealing with large or numerous objects.

    Stack allocation for simplicity and performance when the object's
    lifetime is limited to a function's scope.
*/