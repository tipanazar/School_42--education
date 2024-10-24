#pragma once

#include <iostream>

class Zombie
{
private:
    std::string _name; // Zombie's name

public:
    void setName(std::string name);
    ~Zombie();
    void announce();
};

Zombie *zombieHorde(int N, std::string name);