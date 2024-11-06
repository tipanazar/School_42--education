#include "Weapon.hpp"

Weapon::Weapon(const std::string &_type)
{
    type = _type;
    // this->type = _type;
}

// Weapon::~Weapon()
// {
// }

const std::string &Weapon::getType()
{
    // return (this->type);
    return (type);
}
