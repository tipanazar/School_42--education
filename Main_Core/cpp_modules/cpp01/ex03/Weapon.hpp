#pragma once

#include <iostream>

class Weapon
{
private:
    std::string type;

public:
    const std::string &getType();
    void setType(const std::string &type);
    Weapon(const std::string &type);
    // ~Weapon();
};