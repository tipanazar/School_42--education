#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), (Weapon)weapon(nullptr)
{

}

void HumanB::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = weapon;
}