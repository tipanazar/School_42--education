#pragma once

#include <iostream>

class Weapon
{
private:
    std::string _type;

public:
    const std::string &getType();
    void setType(std::string type);
    Weapon(const std::string &type);
};