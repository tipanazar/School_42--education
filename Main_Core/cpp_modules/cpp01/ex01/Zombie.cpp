#include "Zombie.hpp"

void Zombie::setName(std::string name)
{
    _name = name;
}

Zombie::~Zombie()
{
    std::cout << "Say bye to: " << _name << "." << std::endl;
}

void Zombie::announce()
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}