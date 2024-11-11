#include "Weapon.hpp"

Weapon::Weapon(const std::string &type)
{
    _type = type;
}

const std::string &Weapon::getType()
{
    return (_type);
}

void Weapon::setType(std::string type)
{
    _type = type;
}
