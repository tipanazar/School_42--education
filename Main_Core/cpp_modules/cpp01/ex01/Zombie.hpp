#pragma once

#include <iostream>

class Zombie
{
private:
    std::string _name; 

public:
    void setName(std::string name);
    ~Zombie();
    void announce();
};

Zombie *zombieHorde(int N, std::string name);